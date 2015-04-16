#include "Mapcreator.h"

//Функция, рисующая линию
//                  коорд. i  | коорд. j |  длина линии |  направление    |    линия чего 
void Mapcreator::makeLine(int iFrom, int jFrom, int lineLength, string lineWhere, cell lineOfWhat, cell **floor)
{
	if (lineWhere == "right")
		for (int j = jFrom; j < jFrom + lineLength; j++)
			floor[iFrom][j] = lineOfWhat;
	if (lineWhere == "left")
		for (int j = jFrom; j > jFrom - lineLength; j--)
			floor[iFrom][j] = lineOfWhat;
	if (lineWhere == "up")
		for (int i = iFrom; i > iFrom - lineLength; i--)
			floor[i][jFrom] = lineOfWhat;
	if (lineWhere == "down")
		for (int i = iFrom; i < iFrom + lineLength; i++)
			floor[i][jFrom] = lineOfWhat;
}

//Функция, размещающая бонус в случайном месте карты
void Mapcreator::spawnBonus(int len,int wid, cell **floor)
{
	if (bonusCount < 15)
	{
		srand(time(0));
		int b = (rand() % 2 + 1);
		if (b == 2)
		{
			int i = (rand() % (len - 3) + 2);
			int j = (rand() % (wid - 3) + 2);
			if (floor[i][j] != cell::WALL && floor[i][j] != cell::PLAYER1 && floor[i][j] != cell::PLAYER2 && floor[i][j] != cell::BONUS)
			{
				floor[i][j] = cell::BONUS;
				bonusCount += 1;
			}
		}
	}
}
