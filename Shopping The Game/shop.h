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
<<<<<<< HEAD
	//����������� �� ���������
	shop();

	//����������� ����� � �������� ��������
=======
	//Конструктор по умолчанию
	shop();

	//Конструктор карты с заданным размером
>>>>>>> 69da897dd26650acb68e5dee39d5f4e123e412ca
	shop (int g, int h);

	//����������
	~shop ();
}; 

