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
	//����������� ����� � �������� ��������
	shop (int g, int h);

	//����������
	~shop ();

	//�������, �������� �����
	//                  �����. i  | �����. j |  ����� ����� |  �����������    |    ����� ���� 
	void makeLine(int iFrom, int jFrom, int lineLength, string lineWhere, cell lineOfWhat);

	//�������, ����������� ����������� �����������
	int move(cell r);

	//�������, ����������� ����� � ��������� ����� �����
	void spawnBonus ();

	//�����
	void f_out();
}; 

