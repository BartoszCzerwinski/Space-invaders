//
// Created by piotr on 27.03.19.
//

#include "cGracz.h"
#include"cKula.h"

cGracz::cGracz(double a, double b, double x, double y,int zycia) : cFigura(x,y), a_(a), b_(b) {
	this->zycia_ = zycia;
 ustaw_geometria(x,y,-0.477,0,0.477,0.5);
}

cKula* cGracz::ognia()
{
	return pocisk_ = new cKula(0.1, 0.1, x_, y_-1.8, 90);
}

void cGracz::rysuj() {

	//pozioma belka duza ===============

    glPushMatrix();

    glTranslated(x_, y_-2.4, 0.0);
    glRotated(0, 1.0, 0.0, 0.0);
    glRotated(0, 0.0, 1.0, 0.0);
    glRotated(0, 0.0, 0.0, 1.0);

    glColor3d(1.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
    {
        glVertex3d(-0.477, 0.1, 0);
        glVertex3d(0.477, 0.1, 0);
        glVertex3d(0.477,0, 0);
        glVertex3d(-0.477, 0, 0);
    }
    glEnd();
    glPopMatrix();

	//pionowa belka  ==================

	glPushMatrix();

	glTranslated(x_, y_-2.4, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(-0.0954, 0.5, 0);
		glVertex3d(0.0954, 0.5, 0);
		glVertex3d(0.0954, 0, 0);
		glVertex3d(-0.0954, 0, 0);
	}
	glEnd();
	glPopMatrix();

	//pozioma mala belka

	glPushMatrix();

	glTranslated(x_, y_-2.4, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(-0.2862, 0.3, 0);
		glVertex3d(0.2862, 0.3, 0);
		glVertex3d(0.2862, 0.2, 0);
		glVertex3d(-0.2862, 0.2, 0);
	}
	glEnd();
	glPopMatrix();

}

