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
	//����������� ����� � �������� ��������
	shop (int g, int h);
	
	//����������
	~shop ();

	//�������, ����������� ����������� �����������
	int move(int r);

	//�������, ����������� ����� � ��������� ����� �����
	void setBonus ();

	//�����
	void f_out();
}; 

