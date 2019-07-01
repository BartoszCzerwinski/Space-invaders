
//
// Created by piotr on 27.03.19.
//

#include "cScena.h"
#include <iostream>
#include <chrono>
#include<Windows.h>
#include<ctime>

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
	czas_strzalu_kosmitow_ = 0;
	rysuj_gracza_ = 1;
	rysuj_beleczke1_ = 1;
	rysuj_beleczke2_ = 1;
	rysuj_beleczke3_ = 1;
}


void cScena::myszka(int button, int state, int x, int y)
{
	double openglX = ((double)x - 400) / 800 * 6.68;
	double openglY = (-1)*((double)y - 300) / 600 * 5;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{

		rysuje_pocisk_ = 1;
		pocisk_ = gracz_->ognia();
		int licznik = 0;
		for (int i = 0;i < pociski_.size();i++)
		{
			if (pociski_[i]->get_ID()==1)
			{
				licznik++;
			}
		}
		if (licznik != 3)
			pociski_.push_back(pocisk_);
		/*if (pociski_.size() != 3)
			pociski_.push_back(pocisk_);*/
		

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
	
	

	/// LOSOWANIE KTORY KOSMITA STRZELA ================================

	std::vector<int> spis_odnotowanych;
	int odnotowany;
	if (czas_strzalu_kosmitow_ == 20)
	{
		czas_strzalu_kosmitow_ = 0;
		srand(time(NULL));
		for (int i = 0;i < kosmici_.size();i++)
		{
			
			odnotowany= rand() % 4 + 1;
			if(odnotowany<kosmici_.size())
			spis_odnotowanych.push_back(odnotowany);
		}

		std::vector<int> te_do_strzelenia;
		int licznik = 0, tmp;

		for (int i = 0;i < spis_odnotowanych.size();i++)
		{
			for (int j = 0;j < spis_odnotowanych.size();j++)
			{
				if (spis_odnotowanych[i] == spis_odnotowanych[j])
				{
					tmp = spis_odnotowanych[i];
					licznik++;
				}
			}
			if (licznik == 1)
			{
				te_do_strzelenia.push_back(tmp);
			}
			licznik = 0;
		}

		for (int i = 0;i < te_do_strzelenia.size();i++)
		{
			pocisk_ = kosmici_[te_do_strzelenia[i]]->ognia();
			pociski_.push_back(pocisk_);
		}

	}
	
	///==============================================================================
	
	if (kosmici_.size() == 0)
	{




		if ((ogranicznik_poziomu_ == 1) || (ogranicznik_poziomu_ == 2))     /// Tutaj zwiêksza nam poziomy przy tworzeniu nowych kosmitów
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
		kosmici_[i]->obracaj_kosmite();
		
	}



	for (int i = 0;i < pociski_.size();i++)
	{
		if (pociski_[i]->kolizja(*belka_1_))
		{
			
			pociski_.erase(pociski_.begin() + i);
			belka_1_->zmniejsz_zycie_belki();
			if (belka_1_->get_zycia_belki() == 0)
			{

				delete belka_1_;
				rysuj_beleczke1_ = 0;

			}
			break;
		}

		if (pociski_[i]->kolizja(*belka_2_))                               
		{
		
			pociski_.erase(pociski_.begin() + i);
			belka_2_->zmniejsz_zycie_belki();
			if (belka_2_->get_zycia_belki() == 0)
			{
				delete belka_2_;
				rysuj_beleczke2_ = 0;
			}
			break;
		}

		if (pociski_[i]->kolizja(*belka_3_))
		{
		
			
			pociski_.erase(pociski_.begin() + i);
			belka_3_->zmniejsz_zycie_belki();
			if (belka_3_->get_zycia_belki() == 0)
			{
				delete belka_3_;
				rysuj_beleczke3_ = 0;
			}
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
				if ((pociski_[i]->kolizja(*kosmici_[j]))&&(pociski_[i]->get_ID()==1))
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
		if ((pociski_[i]->kolizja(*gracz_)) && pociski_[i]->get_ID() == 0)
		{
			pociski_.erase(pociski_.begin() + i);
			gracz_->zmniejsz_zycia();
			
		}
	}


	for (int i = 0;i < pociski_.size();i++)
	{
		if (pociski_[i]->get_polozenie_y() >= 2.5)              ///Usuwanie pocisku po przekroczeniu pozycji 2.5
			pociski_.erase(pociski_.begin() + i);

	}

	for (int i = 0;i < pociski_.size();i++)
	{
		if (pociski_[i]->get_polozenie_y() <=-2.5 )              ///Usuwanie pocisku po przekroczeniu pozycji -2.5
			pociski_.erase(pociski_.begin() + i);

	}

	if (gracz_->get_zycia() == 0)
	{
		rysuj_gracza_ = 0;
		delete gracz_;
	}

	czas_strzalu_kosmitow_++;

	glutPostRedisplay();
	glutTimerFunc(40, timer_binding, 0);
}

void cScena::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		if(rysuj_gracza_==1)
		gracz_->rysuj();

		if(rysuj_beleczke1_==1)
		belka_1_->rysuj();

		if(rysuj_beleczke2_==1)
		belka_2_->rysuj();

		if(rysuj_beleczke3_==1)
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


//// POTRZEBNE
/*	
	#include<Windows.h>
	#include<ctime>

	srand(time(NULL));
	float liczba_okruchow;
	liczba_okruchow = rand() % 10 + 4;

	*/