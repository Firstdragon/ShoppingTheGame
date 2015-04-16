#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace 
			std;

class shop
{
private:
	enum class cell { BLANK, WALL, PLAYER1, PLAYER2, BONUS };
	int len;
	int wid;
	cell **floor;
	unsigned short moveKeys;
	int happiness_p1;
	int happiness_p2;
	int bonusCount;
public:
	//Конструктор карты с заданным размером
	shop (int g, int h);

	//Деструктор
	~shop ();

	//Функция, рисующая линию
	//                  коорд. i  | коорд. j |  длина линии |  направление    |    линия чего 
	void makeLine(int iFrom, int jFrom, int lineLength, string lineWhere, cell lineOfWhat);

	//Функция, проверяющая возможность перемещения
	int move(cell r);

	//Функция, размещающая бонус в случайном месте карты
	void spawnBonus ();

	//Вывод
	void f_out();
}; 

