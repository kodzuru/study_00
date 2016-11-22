/*
#pragma once
#include <windows.h>
#include <glut.h>

void Initialize()
{
	//Выбрать фоновый (очищающий) цвет
	glClearColor(1.0, 0.0, 1.0, 1.0);

	//Установить проекцию
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void Draw()
{
	//Очищаем экран glClear(GL_COLOR_BUFFER_BIT);

	//Отрисовка квадрата 
	glColor3f(1.0, 1.0, 1.0); //Выбираем белый цвет
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0); //Координаты квадрата
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glFlush();
}

//Войти в главный цикл
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);		//Указываем размер окна
	glutInitWindowPosition(100, 100);	//Позиция окна
	glutCreateWindow("Polygon");		//Имя окна
	Initialize();						//Вызов функции Initialize
	glutDisplayFunc(Draw);				//Вызов функции отрисовки
	glutMainLoop();

	return 0;
}
*/
#pragma once
#include <glut.h>


void Draw()  //функция рисования
{
	glClear(GL_COLOR_BUFFER_BIT); //рисуем фон
	glEnable(GL_ALPHA); //подключение рисования для прозрачности
	glEnable(GL_BLEND); //подключение типа смешения
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//устанавливает тип смешения
	//glColor3f(1.0, 1.0, 1.0); //цвет рисования	
	glPushMatrix(); //скопировали матрицу рисования
	//рассчёт масштаба
	//Angle %= 360; //чтобы при больше 360 сбрасывалось на 0
	//Scale = 1.0 - abs(sin(3.14*Angle / 90.0) / sqrt(3.0) / 2); // мат функция для рассчёта масштаба
	//glScalef(Scale, Scale, 1.0); // функция изменения масштаба, сжатие масштаба
	
	//рисуем сферу со сдвигом осей координат
	/*
	glColor3f(1.0, 1.0, 0.0);//цвет сферы
	glMatrixMode(GL_MODELVIEW); //Перенастройка типа матрицы GL_MODELVIEW - модель
	glLoadIdentity(); //сбрасываем единичную матрицу
	glTranslatef(0.0, 50.0, 0.0); //поворачиваем
	glutSolidSphere(25.0, 10, 100); //рисуем сферу (радиус, сколько колец по Z, сколько линий по Z)
	glLoadIdentity();//сбрасываем единичную матрицу
	glTranslatef(50.0, 0.0, 0.0);//поворачиваем
	glutSolidSphere(25.0, 10, 100); //рисуем сферу
	*/

	{
		//glRotatef(Angle, 0.0, 0.0, 1.0);
		glBegin(GL_LINE); //начало рисования GL_POINTS - точка GL_LINES - линия, GL_LINE_LOOP - замкнутая линия
		{
			//рисуем сетку
			{
				//тянем сетку мышью
				/*
				for (float i = 0 + x; i <= WinWid + x; i += 20) {

					//вертикальные линии
					glVertex2f(i, 0+y);
					glVertex2f(i, WinHei + y);

				}
				for (float i = 0+y; i <= WinHei + y; i += 20) {

					//горизонтальные линии
					glVertex2f(0+x, i);
					glVertex2f(WinWid+x, i);
					//std::cout << i << "   " << -WinHei / 2 << " | " << i << "  " << WinHei / 2 << endl;
				}
				*/
				//просто сетка		
				/*
				for (float i = -WinWid; i <= WinWid; i += 20) {

					//вертикальные линии
					glVertex2f(i, -WinHei);
					glVertex2f(i, WinHei);

				}
				for (float i = -WinHei; i <= WinHei; i += 20) {

					//горизонтальные линии
					glVertex2f(-WinWid, i);
					glVertex2f(WinWid, i);
					//std::cout << i << "   " << -WinHei / 2 << " | " << i << "  " << WinHei / 2 << endl;
				}
				*/
			}
			//рисуем наши объекты класса круг
			{
				//по очереди достаём каждый круг из вектора с помощью итератора
				/*
				for (std::vector<Circle>::iterator i = circ.begin(); i != circ.end(); i++) {
					i->draw(); //рисуем круг
				}
				*/
				//если количество объектов не определено
				/*
				std::vector<Circle>::iterator i = circ.begin();
				while ( i != circ.end()) {
					i->draw(); //рисуем круг.
					//когда параметр альфа станосится таким то удаляем круг
					if (i->alpha <= 0.05f) {
						i = circ.erase(i); //удаляет круг из векрора
					}
					else {
						i++;
					}					
				}
				*/
			}
		}
		
		glEnd(); //конец рисования
	}
	
	//strcpy(ang, res); //копируем строку из резерваб затем канкатинируем нё с буфером
	//glutSetWindowTitle(strcat(ang, _itoa(Angle, buf, 10))); //устанавливаем титул окна из буфера
	glDisable(GL_BLEND); //отключаем смешение
	glDisable(GL_ALPHA);//отключаем прозрачность
	glPopMatrix(); //востановить копиюю матрицы рисования
	glutSwapBuffers(); //при использовании двойного буфера GLUT_DOUBLE
	//glFlush(); //исполнить все другие команды(указатель) GLUT_SINGLE
}
void Initialize() //функция инициализации
{
	
	glClearColor(0.0,0.0, 0.0, 0.0);//каким цветом всё стереть
	
	glMatrixMode(GL_PROJECTION);//тип матрицы который будет изменять в последующем GL_PROJECTION - матрица проекций
	glLoadIdentity(); //загружаем единичную матрицу
	//рисуем сетку на которые накладываются точки
	glOrtho(-WinWid/2, WinWid/2, -WinHei /2, WinHei/2, -200.0, 200.0); //задаётся сетка координат(матрица проекции) относительно центра экрана
	//glOrtho(0, WinWid, WinHei, 0, -200.0, 200.0); //задаётся сетка координат(матрица проекции) относительно левого верхнего угла
	//все последующие изменения буду касаться матрицы модели
	glMatrixMode(GL_MODELVIEW); //Перенастройка типа матрицы GL_MODELVIEW - модель
	/* lesson 2
	glTranslatef(0.0, 0.0, 0.0); //сдвигает матрицу проекций
	glScalef(0.9,0.9,1.0); // На сколько нужно сжать
	glRotatef(25.0, 5.0,0.0,-1.0); //на сколько повернуть
	*/
}
void Timer(int value) //функция анимации(функция таймера)
{
	//рисуем анимацию нашего объекты класса круг
	{
		/*
		//по очереди достаём каждый круг из вектора с помощью итератора
		for (std::vector<Circle>::iterator i = circ.begin(); i != circ.end(); i++) {
			i->r++; //увеличиваем радиус рисования
			//уменьшаем прозрачность 
			i->alpha/=1.05; //контроллер для убирание окружностей и визуальный эффект
		}
		*/
	}
	//анимация цвета рисования
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
	//Обновление всего рисования можно вызвать Draw()
	glutPostRedisplay(); //обновление всего экрана. того что нарисовали
	glutTimerFunc(1, Timer, 0); //обновления функции инициализации(функции таймера):типа рекурсия
}
//Таймер 2

void Timer2(int)//функция анимации 2 (функция таймера 2 )
{
	//создаём круги только когда нажали
	/*
	if (down)	
	{
		Circle c(X, Y, 10.0); //прикрепляем уоординаты круга к переменным X Y
		circ.push_back(c); //запушиваем этот круг в ветрок
	}
	*/
	//Circle c(rand() % int(WinWid) - WinWid / 2, rand() % int(WinHei) - WinHei / 2, rand() % 20); //создаём объект класса круг
	//Circle c(X, Y, 10.0); //прикрепляем уоординаты круга к переменным X Y
	//circ.push_back(c); //запушиваем этот круг в ветрок

	glutPostRedisplay();
	glutTimerFunc(2, Timer2, 0);
}


//взаимодействие с клавиатурой
/*
void Keyboard(unsigned char key, int x, int y) //функция взаимодействия с клавиатурой 1 ASCII
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
void SKeyboard(int key, int x, int y)  //функция взаимодействия с клавиатурой 2 НЕ ASCII
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

//функции заботы с мышью
void MouseMove(int ax, int ay) //движение мыши без нажатия кнопок
{
	//x = ax;
	//y = ay;
	//glutSetWindowTitle("MouseMove called");
	std::cout << "ax " << ax << "  ay  " << ay << std::endl;
}
void MousePressed(int button, int state, int ax, int ay) //событие на клик
{
	//события на нажатия мышиных кнопок
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
		//state {GLUT_UP нажимаем мышь, GLUT_DOWN отпускаем мышь}
	}
	*/
	//события на мышку и передача координат
	/*
	down = button == GLUT_LEFT_BUTTON && state == GLUT_LEFT; // левая кнопка + именно нажата
	if (down) //записываем координаты
	{
		X = ax;
		Y = ay;
	}
	*/
	//glutSetWindowTitle("MousePressed called");
	std::cout << "ax " << ax << "  ay  " << ay << std::endl;
}
void MousePressedMove(int ax, int ay) //движение при нажатой одной++
{
	/*
	
	if (down) //если нажата то записываем координаты
	{
		X = ax;
		Y = ay;
	}
	*/
	//glutSetWindowTitle("MousePressedMove called");
	std::cout << "ax " << ax << "  ay  " << ay << std::endl;
}
//функции МЕНЮ начало
/*
void MenuCheck(int v) //функция для вызова необходимого нам меню
{
	switch (v) //обработчик вызова меню
	{
	case 0:
		glutSetWindowTitle("Lesson 08");
		break;
	case 1:
		glutSetWindowTitle("Made by admiralCOCO");
		break;
	}
}
void SubMenuCkeck(int v) //функция для вызова необходимого нам подменю.
{
	switch (v)
	{
	case 5:
		glutSetWindowTitle("subMENU by admiralCOCO");
		break;
	}
}
void MenuInit() //функция создания меню
{
	int M = glutCreateMenu(MenuCheck); // создаём меню. функция возвращает ID принимает параметр указатель на функцию
	int Msub = glutCreateMenu(SubMenuCkeck);//создаём подменю
	glutSetMenu(Msub); //указываем какое именно меню выбираем|с каким меню будем работать
	glutAddMenuEntry("subMENU by admiralCOCO", 5);
	glutSetMenu(M); //указываем какое именно меню выбираем
	glutAddMenuEntry("Made by admiralCOCO", 1); //создаём меню принимает имя и переменную V->MenuCheck
	glutAddMenuEntry("Lesson 08", 0); 
	glutAddSubMenu("subMENU", Msub);
	glutRemoveMenuItem(1); //удаляет элемент меню
	glutAttachMenu(GLUT_RIGHT_BUTTON);//сообщаем на какую кнопку мыши приходится наше меню
	//glutDetachMenu(GLUT_RIGHT_BUTTON); //снимает действие с кнопки
}
*/
//функции МЕНЮ конец