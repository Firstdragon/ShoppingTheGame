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
	//�������, �������� �����
	//                  �����. i  | �����. j |  ����� ����� |  �����������    |    ����� ���� 
	void makeLine(int iFrom, int jFrom, int lineLength, string lineWhere, cell lineOfWhat, cell **floor);

	//�������, ����������� ����� � ��������� ����� �����
	void spawnBonus(int len, int wid, cell **floor);
};