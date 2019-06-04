
//
// Created by piotr on 27.03.19.
//

#include "cScena.h"
#include <iostream>
#include <chrono>
cScena::cScena() : active_id_(0) {

	gracz_ = new cGracz(1, 1, 0, 0, 3);
	belka_1_ = new cBelka(0.954, 0.3, 0, -1.5);
	belka_2_ = new cBelka(0.954, 0.3, -2, -1.5);
	belka_3_ = new cBelka(0.954, 0.3, 2, -1.5);
	rysuje_pocisk_ = 0;
	rysuj_kosmite_ = 1;
	sprawdzalnik_ = 0;
	ogranicznik_poziomu_ = 1;
	kosmita_1 = new cKosmita(0.954, 0.5, -1, 0, -1, 0, 1);
	kosmici_.push_back(kosmita_1);
	kosmita_1 = new cKosmita(0.954, 0.5, -1, 0.6, -1, 0.6, 1);
	kosmici_.push_back(kosmita_1);
	kosmita_1 = new cKosmita(0.954, 0.5, 0, 0, 0, 0, 1);
	kosmici_.push_back(kosmita_1);
	kosmita_1 = new cKosmita(0.954, 0.5, 0, 0.6, 0, 0.6, 1);            ///Zamienic 3 na 1 !
	kosmici_.push_back(kosmita_1);
	kosmita_1 = new cKosmita(0.954, 0.5, 1, 0, 1, 0, 1);
	kosmici_.push_back(kosmita_1);
	kosmita_1 = new cKosmita(0.954, 0.5, 1, 0.6, 1, 0.6, 1);
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
		if (pociski_.size() != 3)
			pociski_.push_back(pocisk_);


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
	const float ar = (float)width / (float)height;

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

	if (kosmici_.size() == 0)
	{




		if ((ogranicznik_poziomu_ == 1) || (ogranicznik_poziomu_ == 2))
		{
			int i = ogranicznik_poziomu_;
			kosmita_1 = new cKosmita(0.954, 0.5, -1, 0, -1, 0, 1 + i);
			kosmici_.push_back(kosmita_1);
			kosmita_1 = new cKosmita(0.954, 0.5, -1, 0.6, -1, 0.6, 1 + i);
			kosmici_.push_back(kosmita_1);
			kosmita_1 = new cKosmita(0.954, 0.5, 0, 0, 0, 0, 1 + i);
			kosmici_.push_back(kosmita_1);
			kosmita_1 = new cKosmita(0.954, 0.5, 0, 0.6, 0, 0.6, 1 + i);
			kosmici_.push_back(kosmita_1);
			kosmita_1 = new cKosmita(0.954, 0.5, 1, 0, 1, 0, 1 + i);
			kosmici_.push_back(kosmita_1);
			kosmita_1 = new cKosmita(0.954, 0.5, 1, 0.6, 1, 0.6, 1 + i);
			kosmici_.push_back(kosmita_1);
			ogranicznik_poziomu_++;

		}
	}


	for (int i = 0;i < kosmici_.size();i++)
	{
		kosmici_[i]->kosmita_lata();
	}



	for (int i = 0;i < pociski_.size();i++)
	{
		if (pociski_[i]->kolizja(*belka_1_))
		{
			pociski_.erase(pociski_.begin() + i);
			break;
		}

		if (pociski_[i]->kolizja(*belka_2_))
		{
			pociski_.erase(pociski_.begin() + i);
			break;
		}

		if (pociski_[i]->kolizja(*belka_3_))
		{
			pociski_.erase(pociski_.begin() + i);
			break;
		}
	}



	for (int i = 0;i < pociski_.size();i++)
	{
		pociski_[i]->aktualizuj(GetTickCount());
	}

	int zapamietnik = -1;
	for (int i = 0;i < pociski_.size();i++)
	{
		for (int j = 0;j < kosmici_.size();j++)
		{
			if ((pociski_.size() != 0) && (zapamietnik != i))      /// Haks dzieki niemu nie wywala z tym zapamietnikiem 
			{
				if (pociski_[i]->kolizja(*kosmici_[j]))
				{
					pociski_.erase(pociski_.begin() + i);
					zapamietnik = i;
					kosmici_[j]->kosmita_traci_poziom();
					if (kosmici_[j]->get_poziom() == 0)
					{
						kosmici_.erase(kosmici_.begin() + j);
					}
				}

			}
		}
	}

	for (int i = 0;i < pociski_.size();i++)
	{
		if (pociski_[i]->get_polozenie_y() >= 2.5)
			pociski_.erase(pociski_.begin() + i);
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

		for (int i = 0;i < pociski_.size();i++)
		{
			pociski_[i]->rysuj();
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
		pociski_.push_back(pocisk_);
		break;
	}
	}


}

cScena::~cScena() {
	for (auto &el : figury_)
		delete el;
}
