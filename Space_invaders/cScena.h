//
// Created by piotr on 27.03.19.
//

#ifndef FREEGLUT_CSCENA_H
#define FREEGLUT_CSCENA_H
#include "cGracz.h"
#include"cBelka.h"
#include"cKula.h"
#include"cKosmita.h"
#include <vector>
#include<sstream>

//bindingi dla callbacków
void resize_binding(int width, int height);
void idle_binding();
void display_binding();
void key_binding(unsigned char key, int x, int y);
void timer_binding(int i);
void ruszanie_myszka(int x, int y);
void onMouseButton(int button, int state, int x, int y);

class cScena {
	std::vector<cFigura*> figury_;
	int active_id_;
	cGracz* gracz_;
	cBelka* belka_1_;
	cBelka* belka_2_;
	cBelka* belka_3_;
	cKula* pocisk_;
	std::vector<cKula*> pociski_;
	cKosmita* kosmita_1;
	std::vector<cKosmita*> kosmici_;
	int rysuje_pocisk_;
	int rysuj_kosmite_;
	int ogranicznik_poziomu_;
	int czas_strzalu_kosmitow_;
	int rysuj_gracza_;
	int rysuj_beleczke1_;
	int rysuj_beleczke2_;
	int rysuj_beleczke3_;
	int do_wyswietlenie_0_;
	int ostatni_zapis_;


public:
	cScena();
	~cScena();
	void resize(int width, int height);
	void timer();
	void display();
	void init(int argc, char *argv[], const char* window_name);
	void set_callbacks();
	void key(unsigned char key, int x, int y);
	void podazanie_za_myszka(float x, float y);
	void myszka(int button, int state, int x, int y);
};


#endif //FREEGLUT_CSCENA_H
