//#pragma warning(disable: 4996) //убирает варнинги 
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
#include "Circle.h" // класс круг

float WinWid = 800.0;
float WinHei = 600.0;
std::vector<Circle> circ; //создаём вектор класса круг
float X = 0.0; float Y = 0.0; // координаты мыши от которых убегают шары
bool down = false; //нажата ли кнопка мыши?

/*
int Angle = 0.0; //угол поворота матрицы рисования
float Scale = 1.0; //переменная масштаба
float x = 0.0, y = 0.0;
*/
/*
char ang[7 + 5] = "Angle: "; //указатель на строку шаблон
char res[7 + 5] = "Angle: "; //резервная копия
char buf[5]; //строка вывода в титул угла
*/


#include "start_code.h" // различные функции




using namespace std;
int main(int argc, char** argv) {
	//srand(time(NULL));

	//создание круга
	/*
	// цикл по созданию объектов класса круг
	for (int i(0); i < 2 + rand() % 5; i++) {
		//задаём координаты круга относительно glOrtho в данном случае относительно центра экрана
		Circle c(rand()% int(WinWid) - WinWid/2, rand() % int(WinHei) - WinHei / 2, rand()%20); //создаём объект класса круг
		circ.push_back(c);//запушиваем этот круг в ветрок
	}
	*/

	//инициализация
	glutInit(&argc, argv); // глобальная инициализация
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);// инициализация мода дисплея(как рисуем)
	glutInitWindowSize(WinWid, WinHei); // инициализация размеров дисплея/окна
	glutInitWindowPosition(100, 200); // инициализация позиции окна
	glutCreateWindow("Super <openGL> balalaika"); //создание окна
	//регистрация
	glutDisplayFunc(Draw); //регистрация функции рисования
	//управление мышы
	{
		glutMotionFunc(MousePressedMove);//регистрация когда движение нажали и двигаем
		glutPassiveMotionFunc(MouseMove); //регистрация когда двигается но кнопок не нажато
		glutMouseFunc(MousePressed); //регистрация когда происходит клик
	}
	//glutTimerFunc(1, Timer, 0); // регистрация функции анимации(функция таймера)
	//glutTimerFunc(2, Timer2, 0);  // регистрация функции анимации 2 (функция таймера 2)
	//glutKeyboardFunc(Keyboard); // регистрация функций клавиатуры 1
	//glutSpecialFunc(SKeyboard);// регистрация функций клавиатуры 2 для особых клавиш
	Initialize(); //регистрация функции инициализация
	//MenuInit(); //регистрирует функции меню
	glutMainLoop(); //запуск главного цикла(стандартная функция GLUT)



	_getch();
	return 1;
}