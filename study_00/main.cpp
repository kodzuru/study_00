//#pragma warning(disable: 4996) //������� �������� 
#include <glut.h>
#include <iostream>
#include <conio.h>
#include <math.h>
//#include <random>
//#include <time.h>
//#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include "Circle.h" // ����� ����

float WinWid = 800.0;
float WinHei = 600.0;
std::vector<Circle> circ; //������ ������ ������ ����
float X = 0.0; float Y = 0.0; // ���������� ���� �� ������� ������� ����
bool down = false; //������ �� ������ ����?

/*
int Angle = 0.0; //���� �������� ������� ���������
float Scale = 1.0; //���������� ��������
float x = 0.0, y = 0.0;
*/
/*
char ang[7 + 5] = "Angle: "; //��������� �� ������ ������
char res[7 + 5] = "Angle: "; //��������� �����
char buf[5]; //������ ������ � ����� ����
*/


#include "start_code.h" // ��������� �������




using namespace std;
int main(int argc, char** argv) {
	//srand(time(NULL));

	//�������� �����
	/*
	// ���� �� �������� �������� ������ ����
	for (int i(0); i < 2 + rand() % 5; i++) {
		//����� ���������� ����� ������������ glOrtho � ������ ������ ������������ ������ ������
		Circle c(rand()% int(WinWid) - WinWid/2, rand() % int(WinHei) - WinHei / 2, rand()%20); //������ ������ ������ ����
		circ.push_back(c);//���������� ���� ���� � ������
	}
	*/

	//�������������
	glutInit(&argc, argv); // ���������� �������������
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);// ������������� ���� �������(��� ������)
	glutInitWindowSize(WinWid, WinHei); // ������������� �������� �������/����
	glutInitWindowPosition(100, 200); // ������������� ������� ����
	glutCreateWindow("Super <openGL> balalaika"); //�������� ����
	//�����������
	glutDisplayFunc(Draw); //����������� ������� ���������
	//���������� ����
	{
		glutMotionFunc(MousePressedMove);//����������� ����� �������� ������ � �������
		glutPassiveMotionFunc(MouseMove); //����������� ����� ��������� �� ������ �� ������
		glutMouseFunc(MousePressed); //����������� ����� ���������� ����
	}
	//glutTimerFunc(1, Timer, 0); // ����������� ������� ��������(������� �������)
	//glutTimerFunc(2, Timer2, 0);  // ����������� ������� �������� 2 (������� ������� 2)
	//glutKeyboardFunc(Keyboard); // ����������� ������� ���������� 1
	//glutSpecialFunc(SKeyboard);// ����������� ������� ���������� 2 ��� ������ ������
	Initialize(); //����������� ������� �������������
	//MenuInit(); //������������ ������� ����
	glutMainLoop(); //������ �������� �����(����������� ������� GLUT)



	_getch();
	return 1;
}