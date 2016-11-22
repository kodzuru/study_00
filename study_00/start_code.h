/*
#pragma once
#include <windows.h>
#include <glut.h>

void Initialize()
{
	//������� ������� (���������) ����
	glClearColor(1.0, 0.0, 1.0, 1.0);

	//���������� ��������
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void Draw()
{
	//������� ����� glClear(GL_COLOR_BUFFER_BIT);

	//��������� �������� 
	glColor3f(1.0, 1.0, 1.0); //�������� ����� ����
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0); //���������� ��������
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glFlush();
}

//����� � ������� ����
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);		//��������� ������ ����
	glutInitWindowPosition(100, 100);	//������� ����
	glutCreateWindow("Polygon");		//��� ����
	Initialize();						//����� ������� Initialize
	glutDisplayFunc(Draw);				//����� ������� ���������
	glutMainLoop();

	return 0;
}
*/
#pragma once
#include <glut.h>


void Draw()  //������� ���������
{
	glClear(GL_COLOR_BUFFER_BIT); //������ ���
	glEnable(GL_ALPHA); //����������� ��������� ��� ������������
	glEnable(GL_BLEND); //����������� ���� ��������
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//������������� ��� ��������
	//glColor3f(1.0, 1.0, 1.0); //���� ���������	
	glPushMatrix(); //����������� ������� ���������
	//������� ��������
	//Angle %= 360; //����� ��� ������ 360 ������������ �� 0
	//Scale = 1.0 - abs(sin(3.14*Angle / 90.0) / sqrt(3.0) / 2); // ��� ������� ��� �������� ��������
	//glScalef(Scale, Scale, 1.0); // ������� ��������� ��������, ������ ��������
	
	//������ ����� �� ������� ���� ���������
	/*
	glColor3f(1.0, 1.0, 0.0);//���� �����
	glMatrixMode(GL_MODELVIEW); //������������� ���� ������� GL_MODELVIEW - ������
	glLoadIdentity(); //���������� ��������� �������
	glTranslatef(0.0, 50.0, 0.0); //������������
	glutSolidSphere(25.0, 10, 100); //������ ����� (������, ������� ����� �� Z, ������� ����� �� Z)
	glLoadIdentity();//���������� ��������� �������
	glTranslatef(50.0, 0.0, 0.0);//������������
	glutSolidSphere(25.0, 10, 100); //������ �����
	*/

	{
		//glRotatef(Angle, 0.0, 0.0, 1.0);
		glBegin(GL_LINE); //������ ��������� GL_POINTS - ����� GL_LINES - �����, GL_LINE_LOOP - ��������� �����
		{
			//������ �����
			{
				//����� ����� �����
				/*
				for (float i = 0 + x; i <= WinWid + x; i += 20) {

					//������������ �����
					glVertex2f(i, 0+y);
					glVertex2f(i, WinHei + y);

				}
				for (float i = 0+y; i <= WinHei + y; i += 20) {

					//�������������� �����
					glVertex2f(0+x, i);
					glVertex2f(WinWid+x, i);
					//std::cout << i << "   " << -WinHei / 2 << " | " << i << "  " << WinHei / 2 << endl;
				}
				*/
				//������ �����		
				/*
				for (float i = -WinWid; i <= WinWid; i += 20) {

					//������������ �����
					glVertex2f(i, -WinHei);
					glVertex2f(i, WinHei);

				}
				for (float i = -WinHei; i <= WinHei; i += 20) {

					//�������������� �����
					glVertex2f(-WinWid, i);
					glVertex2f(WinWid, i);
					//std::cout << i << "   " << -WinHei / 2 << " | " << i << "  " << WinHei / 2 << endl;
				}
				*/
			}
			//������ ���� ������� ������ ����
			{
				//�� ������� ������ ������ ���� �� ������� � ������� ���������
				/*
				for (std::vector<Circle>::iterator i = circ.begin(); i != circ.end(); i++) {
					i->draw(); //������ ����
				}
				*/
				//���� ���������� �������� �� ����������
				/*
				std::vector<Circle>::iterator i = circ.begin();
				while ( i != circ.end()) {
					i->draw(); //������ ����.
					//����� �������� ����� ���������� ����� �� ������� ����
					if (i->alpha <= 0.05f) {
						i = circ.erase(i); //������� ���� �� �������
					}
					else {
						i++;
					}					
				}
				*/
			}
		}
		
		glEnd(); //����� ���������
	}
	
	//strcpy(ang, res); //�������� ������ �� �������� ����� ������������� � � �������
	//glutSetWindowTitle(strcat(ang, _itoa(Angle, buf, 10))); //������������� ����� ���� �� ������
	glDisable(GL_BLEND); //��������� ��������
	glDisable(GL_ALPHA);//��������� ������������
	glPopMatrix(); //����������� ������ ������� ���������
	glutSwapBuffers(); //��� ������������� �������� ������ GLUT_DOUBLE
	//glFlush(); //��������� ��� ������ �������(���������) GLUT_SINGLE
}
void Initialize() //������� �������������
{
	
	glClearColor(0.0,0.0, 0.0, 0.0);//����� ������ �� �������
	
	glMatrixMode(GL_PROJECTION);//��� ������� ������� ����� �������� � ����������� GL_PROJECTION - ������� ��������
	glLoadIdentity(); //��������� ��������� �������
	//������ ����� �� ������� ������������� �����
	glOrtho(-WinWid/2, WinWid/2, -WinHei /2, WinHei/2, -200.0, 200.0); //������� ����� ���������(������� ��������) ������������ ������ ������
	//glOrtho(0, WinWid, WinHei, 0, -200.0, 200.0); //������� ����� ���������(������� ��������) ������������ ������ �������� ����
	//��� ����������� ��������� ���� �������� ������� ������
	glMatrixMode(GL_MODELVIEW); //������������� ���� ������� GL_MODELVIEW - ������
	/* lesson 2
	glTranslatef(0.0, 0.0, 0.0); //�������� ������� ��������
	glScalef(0.9,0.9,1.0); // �� ������� ����� �����
	glRotatef(25.0, 5.0,0.0,-1.0); //�� ������� ���������
	*/
}
void Timer(int value) //������� ��������(������� �������)
{
	//������ �������� ������ ������� ������ ����
	{
		/*
		//�� ������� ������ ������ ���� �� ������� � ������� ���������
		for (std::vector<Circle>::iterator i = circ.begin(); i != circ.end(); i++) {
			i->r++; //����������� ������ ���������
			//��������� ������������ 
			i->alpha/=1.05; //���������� ��� �������� ����������� � ���������� ������
		}
		*/
	}
	//�������� ����� ���������
	/*
	{
		switch (value)
		{
		case 0:
			glColor3f(1.0, 1.0, 1.0);
			break;
		case 1:
			glColor3f(1.0, 0.0, 0.0);
			break;
		case 2:
			glColor3f(0.0, 1.0, 0.0);
			break;
		case 3:
			glColor3f(0.0, 0.0, 1.0);
			break;
		}
	}	
	*/
	//++Angle;
	//glRotatef(1.0, 0.0, 0.0, 1.0);
	//���������� ����� ��������� ����� ������� Draw()
	glutPostRedisplay(); //���������� ����� ������. ���� ��� ����������
	glutTimerFunc(1, Timer, 0); //���������� ������� �������������(������� �������):���� ��������
}
//������ 2

void Timer2(int)//������� �������� 2 (������� ������� 2 )
{
	//������ ����� ������ ����� ������
	/*
	if (down)	
	{
		Circle c(X, Y, 10.0); //����������� ���������� ����� � ���������� X Y
		circ.push_back(c); //���������� ���� ���� � ������
	}
	*/
	//Circle c(rand() % int(WinWid) - WinWid / 2, rand() % int(WinHei) - WinHei / 2, rand() % 20); //������ ������ ������ ����
	//Circle c(X, Y, 10.0); //����������� ���������� ����� � ���������� X Y
	//circ.push_back(c); //���������� ���� ���� � ������

	glutPostRedisplay();
	glutTimerFunc(2, Timer2, 0);
}


//�������������� � �����������
/*
void Keyboard(unsigned char key, int x, int y) //������� �������������� � ����������� 1 ASCII
{
	switch (key)
	{
	case 'a':
		Angle += 10;
		break;
	case 'd':
		Angle -= 10;
		break;
	}
}
void SKeyboard(int key, int x, int y)  //������� �������������� � ����������� 2 �� ASCII
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		Angle += 10;
		break;
	case GLUT_KEY_RIGHT:
		Angle -= 10;
		break;
	}
}
*/

//������� ������ � �����
void MouseMove(int ax, int ay) //�������� ���� ��� ������� ������
{
	//x = ax;
	//y = ay;
	//glutSetWindowTitle("MouseMove called");
	std::cout << "ax " << ax << "  ay  " << ay << std::endl;
}
void MousePressed(int button, int state, int ax, int ay) //������� �� ����
{
	//������� �� ������� ������� ������
	/*
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			glutSetWindowTitle("Left button pressed called");
			break;
		case GLUT_RIGHT_BUTTON:
			glutSetWindowTitle("Right button pressed called");
			break;
		case GLUT_MIDDLE_BUTTON:
			glutSetWindowTitle("Middle button pressed called");
			break;
		}
		//state {GLUT_UP �������� ����, GLUT_DOWN ��������� ����}
	}
	*/
	//������� �� ����� � �������� ���������
	/*
	down = button == GLUT_LEFT_BUTTON && state == GLUT_LEFT; // ����� ������ + ������ ������
	if (down) //���������� ����������
	{
		X = ax;
		Y = ay;
	}
	*/
	//glutSetWindowTitle("MousePressed called");
	std::cout << "ax " << ax << "  ay  " << ay << std::endl;
}
void MousePressedMove(int ax, int ay) //�������� ��� ������� �����++
{
	/*
	
	if (down) //���� ������ �� ���������� ����������
	{
		X = ax;
		Y = ay;
	}
	*/
	//glutSetWindowTitle("MousePressedMove called");
	std::cout << "ax " << ax << "  ay  " << ay << std::endl;
}
//������� ���� ������
/*
void MenuCheck(int v) //������� ��� ������ ������������ ��� ����
{
	switch (v) //���������� ������ ����
	{
	case 0:
		glutSetWindowTitle("Lesson 08");
		break;
	case 1:
		glutSetWindowTitle("Made by admiralCOCO");
		break;
	}
}
void SubMenuCkeck(int v) //������� ��� ������ ������������ ��� �������.
{
	switch (v)
	{
	case 5:
		glutSetWindowTitle("subMENU by admiralCOCO");
		break;
	}
}
void MenuInit() //������� �������� ����
{
	int M = glutCreateMenu(MenuCheck); // ������ ����. ������� ���������� ID ��������� �������� ��������� �� �������
	int Msub = glutCreateMenu(SubMenuCkeck);//������ �������
	glutSetMenu(Msub); //��������� ����� ������ ���� ��������|� ����� ���� ����� ��������
	glutAddMenuEntry("subMENU by admiralCOCO", 5);
	glutSetMenu(M); //��������� ����� ������ ���� ��������
	glutAddMenuEntry("Made by admiralCOCO", 1); //������ ���� ��������� ��� � ���������� V->MenuCheck
	glutAddMenuEntry("Lesson 08", 0); 
	glutAddSubMenu("subMENU", Msub);
	glutRemoveMenuItem(1); //������� ������� ����
	glutAttachMenu(GLUT_RIGHT_BUTTON);//�������� �� ����� ������ ���� ���������� ���� ����
	//glutDetachMenu(GLUT_RIGHT_BUTTON); //������� �������� � ������
}
*/
//������� ���� �����