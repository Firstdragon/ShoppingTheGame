#include "shop.h"

shop::shop (int g, int h)
{
	bonusCount = 0;
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
			floor[i][j] = blank;				//Заполняем всё нулями

	//Создание "рамок"
	makeLine(0, 0, wid, "right", wall);      
	makeLine(len - 1, 0, wid, "right", wall);
	makeLine(0, 0, len, "down", wall);
	makeLine(0, wid - 1, len, "down", wall);

	//Создание перекрёстных коридоров
	if (len % 2 == 0)
	{

		makeLine(0, wid / 2 + 2, len / 2 - 2, "down", wall);
		makeLine(0, wid / 2 - 3, len / 2 - 2, "down", wall);
		makeLine(len - 1, wid / 2 + 2, len / 2 - 2, "up", wall);
		makeLine(len - 1, wid / 2 - 3, len / 2 - 2, "up", wall);
	} else {
		makeLine(0, wid / 2 + 2, len / 2 - 1, "down", wall);
		makeLine(0, wid / 2 - 2, len / 2 - 1, "down", wall);
		makeLine(len - 1, wid / 2 + 2, len / 2 - 1, "up", wall);
		makeLine(len - 1, wid / 2 - 2, len / 2 - 1, "up", wall);
	}

	if (wid % 2 == 0)
	{
		makeLine(len / 2 + 2, 0, wid / 2 - 2, "right", wall);
		makeLine(len / 2 - 3, 0, wid / 2 - 2, "right", wall);
		makeLine(len / 2 + 2, wid - 1, wid / 2 - 2, "left", wall);
		makeLine(len / 2 - 3, wid - 1, wid / 2 - 2, "left", wall);
	} else {
		makeLine(len / 2 + 2, 0, wid / 2 - 1, "right", wall);
		makeLine(len / 2 - 2, 0, wid / 2 - 1, "right", wall);
		makeLine(len / 2 + 2, wid - 1, wid / 2 - 1, "left", wall);
		makeLine(len / 2 - 2, wid - 1, wid / 2 - 1, "left", wall);
	}

	if (wid % 2 == 0)							//Создание "дверей"
	{
		makeLine(1, wid / 4 - 2, len - 2, "down", blank);
		makeLine(1, wid / 4 - 1, len - 2, "down", blank);
		makeLine(1, wid / 4 * 3, len - 2, "down", blank);
		makeLine(1, wid / 4 * 3 + 1, len - 2, "down", blank);
	} else {
		makeLine(1, wid / 4 - 2, len - 2, "down", blank);
		makeLine(1, wid / 4 - 1, len - 2, "down", blank);
		makeLine(1, wid / 4 * 3 + 2, len - 2, "down", blank);
		makeLine(1, wid / 4 * 3 + 1, len - 2, "down", blank);
	}

	if (len % 2 == 0)							//Создание "дверей"
	{
		makeLine(len / 4 - 2, 1, wid - 2, "right", blank);
		makeLine(len / 4 - 1, 1, wid - 2, "right", blank);
		makeLine(len / 4 * 3, 1, wid - 2, "right", blank);
		makeLine(len / 4 * 3 + 1, 1, wid - 2, "right", blank);
	} else {
		makeLine(len / 4 - 2, 1, wid - 2, "right", blank);
		makeLine(len / 4 - 1, 1, wid - 2, "right", blank);
		makeLine(len / 4 * 3 + 2, 1, wid - 2, "right", blank);
		makeLine(len / 4 * 3 + 1, 1, wid - 2, "right", blank);
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
			if (floor[i][j] != wall)
			{
				floor[i][j] = bonus;
			}
		}
	}
}


int shop::move(cell r)			//Функция, проверяющая возможность перемещения
{
	if (r == wall)
		return 1;
	if (r == bonus)
		return 3;
	return 0;
}


//Функция, рисующая линию
//                  коорд. i  | коорд. j |  длина линии |  направление    |    линия чего 
void shop::makeLine(int iFrom, int jFrom, int lineLength, string lineWhere, cell lineOfWhat)
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
void shop::spawnBonus ()
{
	if (bonusCount < 15)
	{
		srand(time(0));
		int b = (rand() % 2 + 1);
		if (b == 2)
		{
			int i = (rand() % (len - 3) + 2);
			int j = (rand() % (wid - 3) + 2);
			if (floor[i][j] != wall && floor[i][j] != player1 && floor[i][j] != player2 && floor[i][j] != bonus)
			{
				floor[i][j] = bonus;
				bonusCount += 1;
			}
		}
	}
}

//Вывод
void shop::f_out()				//Вывод магазина
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int player1_i = 2;
	int player1_j = wid / 2;
	int player2_i = len - 2;
	int player2_j = wid / 2;
	floor[player1_i][player1_j] = player1; 
	floor[player2_i][player2_j] = player2;
	happiness_p1 = 0;
	happiness_p2 = 0;
	while (moveKeys != 27)
	{
		spawnBonus();
		system("cls");	
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\tPlayer 1 happiness: " << happiness_p1 << "\t\t\tPlayer 2 happiness: " << happiness_p2 << "\n\n";
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < wid; j++)
			{
				if (floor[i][j] == wall)
				{
					//Вывод символа с кодом 219 в таблице аски 
					cout << static_cast<unsigned char>(219);
				}
				if (floor[i][j] == blank)
				{
					cout << " ";
				}
				if (floor[i][j] == player1)
				{
					SetConsoleTextAttribute(hConsole, 2);
					cout << "1";
					SetConsoleTextAttribute(hConsole, 15);
				}
				if (floor[i][j] == player2)
				{
					SetConsoleTextAttribute(hConsole, 3);
					cout << "2";
					SetConsoleTextAttribute(hConsole, 15);
				}
				if (floor[i][j] == bonus)
				{
					SetConsoleTextAttribute(hConsole, 5);
					cout << "X";
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
			cout << endl;

		}
		
		moveKeys = _getch();
		if (moveKeys == 0)
			moveKeys = _getch();
		if (moveKeys == 72)				//Если стрелка вверх
		{
			// Вверх
			if (move(floor[player1_i - 1][player1_j]) != wall)
			{
				if (floor[player1_i - 1][player1_j] == bonus)
				{
					bonusCount-=1;
					happiness_p1+=100;
				}
				floor[player1_i][player1_j] = blank;
				player1_i--;
				floor[player1_i][player1_j] = player1;
			}
		}
		if (moveKeys == 80)				//Если стрелка вниз
		{
			// Вниз
			if (move(floor[player1_i + 1][player1_j]) != wall)
			{
				if (floor[player1_i + 1][player1_j] == bonus)
				{
					bonusCount-=1;
					happiness_p1+=100;
				}
				floor[player1_i][player1_j] = blank;
				player1_i++;
				floor[player1_i][player1_j] = player1;
			}
		}
		if (moveKeys == 77)				//Если стрелка вправо
		{
			// Вправо
			if (move(floor[player1_i][player1_j + 1]) != wall)
			{
				if (floor[player1_i][player1_j + 1] == bonus)
				{
					bonusCount-=1;
					happiness_p1+=100;
				}
				floor[player1_i][player1_j] = blank;
				player1_j++;
				floor[player1_i][player1_j] = player1;
			}
		}
		if (moveKeys == 75)				//Если стрелка влево
		{
			// Влево
			if (move(floor[player1_i][player1_j - 1]) != wall)
			{
				if (floor[player1_i][player1_j - 1] == bonus)
				{
					bonusCount-=1;
					happiness_p1+=100;
				}
				floor[player1_i][player1_j] = blank;
				player1_j--;
				floor[player1_i][player1_j] = player1;
			}
		}
		///////////////////////////
		if (moveKeys == 119 || moveKeys == 87)				//Если W
		{
			// Вверх
			if (move(floor[player2_i - 1][player2_j]) != wall)
			{
				if (floor[player2_i - 1][player2_j] == bonus)
				{
					bonusCount -= 1;
					happiness_p2 += 100;
				}
				floor[player2_i][player2_j] = blank;
				player2_i--;
				floor[player2_i][player2_j] = player2;
			}
		}
		if (moveKeys == 115 || moveKeys == 83)				//Если S
		{
			// Вниз
			if (move(floor[player2_i + 1][player2_j]) != wall)
			{
				if (floor[player2_i + 1][player2_j] == bonus)
				{
					bonusCount -= 1;
					happiness_p2 += 100;
				}
				floor[player2_i][player2_j] = blank;
				player2_i++;
				floor[player2_i][player2_j] = player2;
			}
		}
		if (moveKeys == 100 || moveKeys == 68)				//Если D
		{
			// Вправо
			if (move(floor[player2_i][player2_j + 1]) != wall)
			{
				if (floor[player2_i][player2_j + 1] == bonus)
				{
					bonusCount -= 1;
					happiness_p2 += 100;
				}
				floor[player2_i][player2_j] = blank;
				player2_j++;
				floor[player2_i][player2_j] = player2;
			}
		}
		if (moveKeys == 97 || moveKeys == 65)				//Если A
		{
			// Влево
			if (move(floor[player2_i][player2_j - 1]) != wall)
			{
				if (floor[player2_i][player2_j - 1] == bonus)
				{
					bonusCount -= 1;
					happiness_p2 += 100;
				}
				floor[player2_i][player2_j] = blank;
				player2_j--;
				floor[player2_i][player2_j] = player2;
			}
		}
	}		//Цикл работает, пока не вводится esс
	system("cls");
	cout << "\n\n\n    TOTAL PLAYER 1 HAPPINESS : " << happiness_p1 << "\t  TOTAL PLAYER 2 HAPPINESS : " << happiness_p2;
	cout << "\n\n\t\t\t\t GAME OVER\n" << endl;
}

//Деструктор
shop::~shop()					//Очистка выделеной памяти
{
	for( int i = 0; i < len; i++ )
		delete [] floor[i];
	delete [] floor;	
}
