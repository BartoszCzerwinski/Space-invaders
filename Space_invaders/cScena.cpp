//
// Created by piotr on 27.03.19.
//

#include "cScena.h"
#include <iostream>
#include <chrono>
cScena::cScena() : active_id_(0) {

	gracz_ = new cGracz(1, 1, 0, 0);
	belka_1_ = new cBelka(0.954, 0.3, 0, -1.5);
	belka_2_ = new cBelka(0.954, 0.3, -2, -1.5);
	belka_3_ = new cBelka(0.954, 0.3, 2, -1.5);
	rysuje_pocisk_ = 0;
	rysuj_kosmite_ = 1;
	sprawdzalnik_ = 0;
	kosmita_1 = new cKosmita(0.954, 0.5, -1, 0,-1,0);
	kosmici_.push_back(kosmita_1);
	kosmita_1 = new cKosmita(0.954, 0.5, -1, 0.6,-1,0.6);
	kosmici_.push_back(kosmita_1);
	kosmita_1 = new cKosmita(0.954, 0.5, 0, 0,0,0);
	kosmici_.push_back(kosmita_1);
	kosmita_1 = new cKosmita(0.954, 0.5, 0, 0.6,0,0.6);
	kosmici_.push_back(kosmita_1);
	kosmita_1 = new cKosmita(0.954, 0.5, 1, 0,1,0);
	kosmici_.push_back(kosmita_1);
	kosmita_1 = new cKosmita(0.954, 0.5, 1, 0.6,1,0.6);
	kosmici_.push_back(kosmita_1);
	
}


void cScena::myszka(int button, int state, int x, int y)
{
	double openglX = ((double)x - 400) / 800 * 6.68;
	double openglY = (-1)*((double)y - 300) / 600 * 5;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{

		rysuje_pocisk_ = 1;
		pocisk_ = gracz_->ognia();
		

	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) 
	{

	
	
	}
	glutPostRedisplay();
}


void cScena::podazanie_za_myszka(float x, float y)
{

	double openglX = ((double)x - 400) / 800 * 6.68;
	double openglY = (-1)*((double)y - 300) / 600 * 5;

	gracz_->aktualizuj_polozenie_x_y(openglX);

	//glutPostRedisplay();

}


void cScena::resize(int width, int height) {
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void cScena::timer() {

    //int current_time = getTickCount();
    //auto current_time = std::chrono::high_resolution_clock::now();

    //std::cout<<current_time<<std::endl;
    //std::cout.flush();

	for (int i = 0;i < kosmici_.size();i++)
	{
		kosmici_[i]->kosmita_lata();
	}
	
 
	if (rysuje_pocisk_ == 1)
	{

		if (pocisk_->kolizja(*belka_1_))
			rysuje_pocisk_ = 0;
		if (pocisk_->kolizja(*belka_2_))
			rysuje_pocisk_ = 0;
		if (pocisk_->kolizja(*belka_3_))
			rysuje_pocisk_ = 0;

		
		pocisk_->aktualizuj(GetTickCount());
		
		
			for (int i = 0;i < kosmici_.size();i++)
			{
				if (pocisk_->kolizja(*kosmici_[i]))
				{
					kosmici_.erase(kosmici_.begin() + i);
					rysuje_pocisk_ = 0;
				}
			}
		
	}


    glutPostRedisplay();
    glutTimerFunc(40, timer_binding, 0);
}

void cScena::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    {
		gracz_->rysuj();
		belka_1_->rysuj();
		belka_2_->rysuj();
		belka_3_->rysuj();
		if (rysuje_pocisk_ == 1)
		{
			pocisk_->rysuj();
		}

		for (int i = 0;i < kosmici_.size();i++)
		{
			kosmici_[i]->rysuj();
		}
    }
    glPopMatrix();

    glutSwapBuffers();
}


void cScena::set_callbacks() {
    glutReshapeFunc(resize_binding);
    glutDisplayFunc(display_binding);
	glutPassiveMotionFunc(ruszanie_myszka);
	glutMouseFunc(onMouseButton);
    //glutIdleFunc(idle_binding);
    glutTimerFunc(40, timer_binding, 0);
    glutKeyboardFunc(key_binding);
}

void cScena::init(int argc, char **argv, const char *window_name) {

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(40, 40);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

    glutCreateWindow(window_name);

    // set white as the clear colour
    glClearColor(0, 0, 0, 1);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    set_callbacks();

    // start GLUT event loop. It ends when user close the window.
    glutMainLoop();
}

void cScena::key(unsigned char key, int x, int y) {
    switch (key) {
        
        case 'z':
		{
			rysuje_pocisk_ = 1;
			pocisk_ = gracz_->ognia();
			break;
        }
    }


}

cScena::~cScena() {
    for (auto &el : figury_)
        delete el;
}
