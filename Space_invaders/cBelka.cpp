#include "cBelka.h"

cBelka::cBelka(double a, double b, double x, double y) : cFigura(x, y), a_(a), b_(b) {
	ustaw_geometria(x, y, -a / 2, -b / 2, a / 2, b / 2);
	this->zycie_belki_ = 3;
	this->zmniejszalnik_ = 0.05;
	
}


int cBelka::get_zycia_belki()
{
	return zycie_belki_;
}

void cBelka::zmniejsz_zycie_belki()
{
	zycie_belki_--;
	ustaw_geometria(x_, y_,-a_/2,-b_/2,a_/2,b_/2-zmniejszalnik_);
	zmniejszalnik_ = zmniejszalnik_ + zmniejszalnik_;

}


void cBelka::rysuj() {
	if (zycie_belki_ == 3)
	{
		glPushMatrix();

		glTranslated(x_, y_, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(0, 0.0, 0.0, 1.0);

		glColor3d(1.0, 0.0, 0.0);

		glBegin(GL_POLYGON);
		{
			glVertex3d(-a_ / 2, b_ / 2, 0);
			glVertex3d(a_ / 2, b_ / 2, 0);
			glVertex3d(a_ / 2, -b_ / 2, 0);
			glVertex3d(-a_ / 2, -b_ / 2, 0);
		}
		glEnd();
		glPopMatrix();
	}

	if (zycie_belki_ == 2)
	{
		glPushMatrix();

		glTranslated(x_, y_, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(0, 0.0, 0.0, 1.0);

		glColor3d(0.5, 0.0, 0.0);

		glBegin(GL_POLYGON);
		{
			glVertex3d(-a_ / 2, (b_ / 2)-0.05, 0);
			glVertex3d(a_ / 2, (b_ / 2)-0.05, 0);
			glVertex3d(a_ / 2, (-b_ / 2)+0.05, 0);
			glVertex3d(-a_ / 2, (-b_ / 2)+0.05, 0);
		}
		glEnd();
		glPopMatrix();
	}

	if (zycie_belki_ == 1)
	{
		glPushMatrix();

		glTranslated(x_, y_, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(0, 0.0, 0.0, 1.0);

		glColor3d(0.5, 0.0, 0.0);

		glBegin(GL_POLYGON);
		{
			glVertex3d(-a_ / 2, (b_ / 2) - 0.1, 0);
			glVertex3d(a_ / 2, (b_ / 2) - 0.1, 0);
			glVertex3d(a_ / 2, (-b_ / 2) + 0.1, 0);
			glVertex3d(-a_ / 2, (-b_ / 2) + 0.1, 0);
		}
		glEnd();
		glPopMatrix();
	}

}

