#pragma once
#include <glut.h>
#include <time.h>
// ����� ����
class Circle
{
public:
	//���������� ���������� ������
	float x, y; //���������� 
	float r; // ������
	float alpha; // ������������
	//����������� �� ������������ �����������
	Circle(float _x = 0.0, float _y = 0.0, float _r = 10.0) :x(_x), y(_y), r(_r), alpha(1.0) {}; 
	~Circle() {};
	void draw() //������� ��������� ��� ����� ������ ����
	{
		glColor4f(1.0, 1.0, 0.0, this->alpha); //������������� ���� RGB+A(������������)
		glBegin(GL_LINE_LOOP);
		// i �������� ���� �� 0 �� 2�� ��
		for (float i = 0.0; i < 2 * 3.14; i += 3.14 / 180) {
			//����� ������� ��� ���������� ����������
			glVertex2f(this->x + this->r*sin(i), this->y + this->r*cos(i));
		}
		glEnd();
	}

};

