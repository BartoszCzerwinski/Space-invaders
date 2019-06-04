#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>
#include "cScena.h"

cScena scena;

void resize_binding(int width, int height) {
	scena.resize(width, height);
}
void idle_binding() {
	//scena.timer();
}
void timer_binding(int msec) {
	scena.timer();
}
void display_binding() {
	scena.display();
}

void key_binding(unsigned char key, int x, int y) {
	scena.key(key, x, y);
}

void ruszanie_myszka(int x, int y)
{
	scena.podazanie_za_myszka(x, y);
}

void onMouseButton(int button, int state, int x, int y)
{
	scena.myszka(button, state, x, y);
}

int main(int argc, char *argv[])
{
	// it's still possible to use console to print messages
	std::cout << "Hello openGL world!" << std::endl;



	scena.init(argc, argv, "Okno sceny");




	return 0;
}