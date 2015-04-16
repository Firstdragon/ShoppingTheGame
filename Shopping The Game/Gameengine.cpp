#include "Gameengine.h"

Mapcreator creator;

int Gameengine::move(cell r)			//Функция, проверяющая возможность перемещения
{
	if (r == cell::WALL)
		return 1;
	if (r == cell::BONUS)
		return 3;
	return 0;
}

void Gameengine::f_out(int len, int wid, cell **floor)				//Вывод магазина
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int player1_i = 2;
	int player1_j = wid / 2;
	int player2_i = len - 2;
	int player2_j = wid / 2;
	floor[player1_i][player1_j] = cell::PLAYER1;
	floor[player2_i][player2_j] = cell::PLAYER2;
	happiness_p1 = 0;
	happiness_p2 = 0;
	while (moveKeys != 27)
	{
		creator.spawnBonus(len, wid, floor);
		system("cls");
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\tPlayer 1 happiness: " << happiness_p1 << "\t\t\tPlayer 2 happiness: " << happiness_p2 << "\n\n";
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < wid; j++)
			{
				if (floor[i][j] == cell::WALL)
				{
					//Вывод символа с кодом 219 в таблице аски 
					cout << static_cast<unsigned char>(219);
				}
				if (floor[i][j] == cell::BLANK)
				{
					cout << " ";
				}
				if (floor[i][j] == cell::PLAYER1)
				{
					SetConsoleTextAttribute(hConsole, 2);
					cout << "1";
					SetConsoleTextAttribute(hConsole, 15);
				}
				if (floor[i][j] == cell::PLAYER2)
				{
					SetConsoleTextAttribute(hConsole, 3);
					cout << "2";
					SetConsoleTextAttribute(hConsole, 15);
				}
				if (floor[i][j] == cell::BONUS)
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
			if (move(floor[player1_i - 1][player1_j]) != 1)
			{
				if (floor[player1_i - 1][player1_j] == cell::BONUS)
				{
					creator.bonusCount -= 1;
					happiness_p1 += 100;
				}
				floor[player1_i][player1_j] = cell::BLANK;
				player1_i--;
				floor[player1_i][player1_j] = cell::PLAYER1;
			}
		}
		if (moveKeys == 80)				//Если стрелка вниз
		{
			// Вниз
			if (move(floor[player1_i + 1][player1_j]) != 1)
			{
				if (floor[player1_i + 1][player1_j] == cell::BONUS)
				{
					creator.bonusCount -= 1;
					happiness_p1 += 100;
				}
				floor[player1_i][player1_j] = cell::BLANK;
				player1_i++;
				floor[player1_i][player1_j] = cell::PLAYER1;
			}
		}
		if (moveKeys == 77)				//Если стрелка вправо
		{
			// Вправо
			if (move(floor[player1_i][player1_j + 1]) != 1)
			{
				if (floor[player1_i][player1_j + 1] == cell::BONUS)
				{
					creator.bonusCount -= 1;
					happiness_p1 += 100;
				}
				floor[player1_i][player1_j] = cell::BLANK;
				player1_j++;
				floor[player1_i][player1_j] = cell::PLAYER1;
			}
		}
		if (moveKeys == 75)				//Если стрелка влево
		{
			// Влево
			if (move(floor[player1_i][player1_j - 1]) != 1)
			{
				if (floor[player1_i][player1_j - 1] == cell::BONUS)
				{
					creator.bonusCount -= 1;
					happiness_p1 += 100;
				}
				floor[player1_i][player1_j] = cell::BLANK;
				player1_j--;
				floor[player1_i][player1_j] = cell::PLAYER1;
			}
		}
		///////////////////////////
		if (moveKeys == 119 || moveKeys == 87)				//Если W
		{
			// Вверх
			if (move(floor[player2_i - 1][player2_j]) != 1)
			{
				if (floor[player2_i - 1][player2_j] == cell::BONUS)
				{
					creator.bonusCount -= 1;
					happiness_p2 += 100;
				}
				floor[player2_i][player2_j] = cell::BLANK;
				player2_i--;
				floor[player2_i][player2_j] = cell::PLAYER2;
			}
		}
		if (moveKeys == 115 || moveKeys == 83)				//Если S
		{
			// Вниз
			if (move(floor[player2_i + 1][player2_j]) != 1)
			{
				if (floor[player2_i + 1][player2_j] == cell::BONUS)
				{
					creator.bonusCount -= 1;
					happiness_p2 += 100;
				}
				floor[player2_i][player2_j] = cell::BLANK;
				player2_i++;
				floor[player2_i][player2_j] = cell::PLAYER2;
			}
		}
		if (moveKeys == 100 || moveKeys == 68)				//Если D
		{
			// Вправо
			if (move(floor[player2_i][player2_j + 1]) != 1)
			{
				if (floor[player2_i][player2_j + 1] == cell::BONUS)
				{
					creator.bonusCount -= 1;
					happiness_p2 += 100;
				}
				floor[player2_i][player2_j] = cell::BLANK;
				player2_j++;
				floor[player2_i][player2_j] = cell::PLAYER2;
			}
		}
		if (moveKeys == 97 || moveKeys == 65)				//Если A
		{
			// Влево
			if (move(floor[player2_i][player2_j - 1]) != 1)
			{
				if (floor[player2_i][player2_j - 1] == cell::BONUS)
				{
					creator.bonusCount -= 1;
					happiness_p2 += 100;
				}
				floor[player2_i][player2_j] = cell::BLANK;
				player2_j--;
				floor[player2_i][player2_j] = cell::PLAYER2;
			}
		}
	}		//Цикл работает, пока не вводится esс
	system("cls");
	cout << "\n\n\n    TOTAL PLAYER 1 HAPPINESS : " << happiness_p1 << "\t  TOTAL PLAYER 2 HAPPINESS : " << happiness_p2;
	cout << "\n\n\t\t\t\t GAME OVER\n" << endl;
}
