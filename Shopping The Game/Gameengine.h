#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "enum.h"
#include "shop.h"
#include "Mapcreator.h"

using namespace std;

class Gameengine
{
private:
	int happiness_p1;
	int happiness_p2;
	unsigned short moveKeys;
public:
	//‘ункци€, провер€юща€ возможность перемещени€
	int move(cell r);

	void f_out(int len, int wid, cell **floor);
};