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
	int len;
	int wid;
	short **floor;
	unsigned short moveKeys;
	int s1;
	int s2;
	int happines;
	int bonusCount;
public:
	//Конструктор карты с заданным размером
	shop (int g, int h);
	
	//Деструктор
	~shop ();

	//Функция, проверяющая возможность перемещения
	int move(int r);

	//Функция, размещающая бонус в случайном месте карты
	void setBonus ();

	//Вывод
	void f_out();
}; 

