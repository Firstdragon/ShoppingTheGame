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
	//����������� �� ���������
	shop();

	//����������� ����� � �������� ��������
	shop (int g, int h);

	//����������
	~shop ();
}; 

