#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "enum.h"

using namespace
std;

struct Mapcreator
{

	int bonusCount;
	//Функция, рисующая линию
	//                  коорд. i  | коорд. j |  длина линии |  направление    |    линия чего 
	void makeLine(int iFrom, int jFrom, int lineLength, string lineWhere, cell lineOfWhat, cell **floor);

	//Функция, размещающая бонус в случайном месте карты
	void spawnBonus(int len, int wid, cell **floor);
};
