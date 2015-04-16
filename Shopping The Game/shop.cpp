#include "shop.h"

shop::shop()
{

}

Mapcreator create;

shop::shop (int g, int h)
{
	create.bonusCount = 0;
	if (g < 16 || h < 16 || g > 20 || h > 50) 
	{
		cout << "ERROR! Length or width are incorrect" << endl;
		system ("pause");
		exit (-1);
	}
	len = g; wid = h;
	floor = new cell *[len];				//Выделяем память под матрицу floor размера len*wid
	for (int i = 0; i < len; i++)
		floor[i] = new cell[wid];

	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
			floor[i][j] = cell::BLANK;				//Заполняем всё нулями

	//Создание "рамок"
	create.makeLine(0, 0, wid, "right", cell::WALL, floor);
	create.makeLine(len - 1, 0, wid, "right", cell::WALL, floor);
	create.makeLine(0, 0, len, "down", cell::WALL, floor);
	create.makeLine(0, wid - 1, len, "down", cell::WALL, floor);

	//Создание перекрёстных коридоров
	if (len % 2 == 0)
	{

		create.makeLine(0, wid / 2 + 2, len / 2 - 2, "down", cell::WALL, floor);
		create.makeLine(0, wid / 2 - 3, len / 2 - 2, "down", cell::WALL, floor);
		create.makeLine(len - 1, wid / 2 + 2, len / 2 - 2, "up", cell::WALL, floor);
		create.makeLine(len - 1, wid / 2 - 3, len / 2 - 2, "up", cell::WALL, floor);
	} else {
		create.makeLine(0, wid / 2 + 2, len / 2 - 1, "down", cell::WALL, floor);
		create.makeLine(0, wid / 2 - 2, len / 2 - 1, "down", cell::WALL, floor);
		create.makeLine(len - 1, wid / 2 + 2, len / 2 - 1, "up", cell::WALL, floor);
		create.makeLine(len - 1, wid / 2 - 2, len / 2 - 1, "up", cell::WALL, floor);
	}

	if (wid % 2 == 0)
	{
		create.makeLine(len / 2 + 2, 0, wid / 2 - 2, "right", cell::WALL, floor);
		create.makeLine(len / 2 - 3, 0, wid / 2 - 2, "right", cell::WALL, floor);
		create.makeLine(len / 2 + 2, wid - 1, wid / 2 - 2, "left", cell::WALL, floor);
		create.makeLine(len / 2 - 3, wid - 1, wid / 2 - 2, "left", cell::WALL, floor);
	} else {
		create.makeLine(len / 2 + 2, 0, wid / 2 - 1, "right", cell::WALL, floor);
		create.makeLine(len / 2 - 2, 0, wid / 2 - 1, "right", cell::WALL, floor);
		create.makeLine(len / 2 + 2, wid - 1, wid / 2 - 1, "left", cell::WALL, floor);
		create.makeLine(len / 2 - 2, wid - 1, wid / 2 - 1, "left", cell::WALL, floor);
	}

	if (wid % 2 == 0)							//Создание "дверей"
	{
		create.makeLine(1, wid / 4 - 2, len - 2, "down", cell::BLANK, floor);
		create.makeLine(1, wid / 4 - 1, len - 2, "down", cell::BLANK, floor);
		create.makeLine(1, wid / 4 * 3, len - 2, "down", cell::BLANK, floor);
		create.makeLine(1, wid / 4 * 3 + 1, len - 2, "down", cell::BLANK, floor);
	} else {
		create.makeLine(1, wid / 4 - 2, len - 2, "down", cell::BLANK, floor);
		create.makeLine(1, wid / 4 - 1, len - 2, "down", cell::BLANK, floor);
		create.makeLine(1, wid / 4 * 3 + 2, len - 2, "down", cell::BLANK, floor);
		create.makeLine(1, wid / 4 * 3 + 1, len - 2, "down", cell::BLANK, floor);
	}

	if (len % 2 == 0)							//Создание "дверей"
	{
		create.makeLine(len / 4 - 2, 1, wid - 2, "right", cell::BLANK, floor);
		create.makeLine(len / 4 - 1, 1, wid - 2, "right", cell::BLANK, floor);
		create.makeLine(len / 4 * 3, 1, wid - 2, "right", cell::BLANK, floor);
		create.makeLine(len / 4 * 3 + 1, 1, wid - 2, "right", cell::BLANK, floor);
	} else {
		create.makeLine(len / 4 - 2, 1, wid - 2, "right", cell::BLANK, floor);
		create.makeLine(len / 4 - 1, 1, wid - 2, "right", cell::BLANK, floor);
		create.makeLine(len / 4 * 3 + 2, 1, wid - 2, "right", cell::BLANK, floor);
		create.makeLine(len / 4 * 3 + 1, 1, wid - 2, "right", cell::BLANK, floor);
	}
	srand(time(0));
	int startBonusCount = (rand() % 12 + 5);
	for (int r = 0; r < startBonusCount; r++)
	{
		int d = (rand() % 2 + 1);
		if (d == 2)
		{
			int i = (rand() % (len - 3) + 2);
			int j = (rand() % (wid - 3) + 2);
			if (floor[i][j] != cell::WALL)
			{
				floor[i][j] =cell::BONUS;
			}
		}
	}
}


//Деструктор
shop::~shop()					//Очистка выделеной памяти
{
	for( int i = 0; i < len; i++ )
		delete [] floor[i];
	delete [] floor;	
}
