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
	//Конструктор по умолчанию
	shop();

	//Конструктор карты с заданным размером
=======
	//РљРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РїРѕ СѓРјРѕР»С‡Р°РЅРёСЋ
	shop();

	//РљРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РєР°СЂС‚С‹ СЃ Р·Р°РґР°РЅРЅС‹Рј СЂР°Р·РјРµСЂРѕРј
>>>>>>> 69da897dd26650acb68e5dee39d5f4e123e412ca
	shop (int g, int h);

	//Деструктор
	~shop ();
}; 

