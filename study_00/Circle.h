#pragma once
#include <glut.h>
#include <time.h>
// класс круг
class Circle
{
public:
	//объявление переменных класса
	float x, y; //координаты 
	float r; // радиус
	float alpha; // прозрачность
	//конструктор со стандартными параметрами
	Circle(float _x = 0.0, float _y = 0.0, float _r = 10.0) :x(_x), y(_y), r(_r), alpha(1.0) {}; 
	~Circle() {};
	void draw() //функция рисования как метод класса круг
	{
		glColor4f(1.0, 1.0, 0.0, this->alpha); //устанавливаем цвет RGB+A(прозрачность)
		glBegin(GL_LINE_LOOP);
		// i проходит круг от 0 до 2ух ПИ
		for (float i = 0.0; i < 2 * 3.14; i += 3.14 / 180) {
			//общая формула для присования окружности
			glVertex2f(this->x + this->r*sin(i), this->y + this->r*cos(i));
		}
		glEnd();
	}

};

