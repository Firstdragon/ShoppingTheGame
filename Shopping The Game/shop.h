#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "Mapcreator.h"
#include "enum.h"

using namespace 
			std;

class shop
{
public:
	int len;
	int wid;
	cell **floor;
	//Конструктор по умолчанию
	shop();

	//Конструктор карты с заданным размером
	shop (int g, int h);

	//Деструктор
	~shop ();
}; 

