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
	floor = new short *[len];				//�������� ������ ��� ������� floor ������� len*wid
	for (int i = 0; i < len; i++)
		floor[i] = new short [wid];
	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)
			floor[i][j] = 0;				//��������� �� ������
	for (int i = 0; i < len; i++)
		for (int j = 0; j < wid; j++)		//����� ��������� ���������
		{
			if (i == 0) 
				floor[i][j] = 1;
			if (i == len-1)
				floor[i][j] = 1;
			if (j == 0) 
				floor[i][j] = 1;
			if (j == wid-1)
				floor[i][j] = 1;
		}

	if (len % 2 == 0)
	{
		for (int i = 0; i < len; i++)			//�������� "������" ������ ����
		{
			floor[i][wid / 2 + 2] = 1;
			floor[i][wid / 2 - 3] = 1;
		}
	} else {
		for (int i = 0; i < len; i++)			//�������� "������" ������ ����
		{
			floor[i][wid / 2 + 2] = 1;
			floor[i][wid / 2 - 2] = 1;
		} 
	}

	if (wid % 2 == 0)
	{
		for (int j = 0; j < wid; j++)			//�������� "������" ����� �������
		{
			floor[len / 2 + 2][j] = 1;
			floor[len / 2 - 3][j] = 1;
		}
	} else {
		for (int j = 0; j < wid; j++)			//�������� "������" ����� �������
		{
			floor[len / 2 + 2][j] = 1;
			floor[len / 2 - 2][j] = 1;
		}
	}

	if (len % 2 == 0)
	{
		for (int i = 1; i < len-1; i++)			//����������� �����������
		{
			floor[i][wid / 2] = 0;
			floor[i][wid / 2 - 1] = 0;
			floor[i][wid / 2 - 2] = 0;
			floor[i][wid / 2 + 1] = 0;
		}
	} else {
		for (int i = 1; i < len-1; i++)			//����������� �����������
		{
			floor[i][wid / 2] = 0;
			floor[i][wid / 2 - 1] = 0;
			floor[i][wid / 2 + 1] = 0;
		}
	}

	if (wid % 2 == 0)
	{
		for (int j = 1; j < wid-1; j++)			//����������� �����������
		{
			floor[len / 2][j] = 0;
			floor[len / 2 - 1][j] = 0;
			floor[len / 2 - 2][j] = 0;
			floor[len / 2 + 1][j] = 0;
		}
	} else {
		for (int j = 1; j < wid-1; j++)			//����������� �����������
		{
			floor[len / 2][j] = 0;
			floor[len / 2 - 1][j] = 0;
			floor[len / 2 + 1][j] = 0;
		}
	}

	if (wid % 2 == 0)							//�������� "������"
	{
		for (int i = 1; i < len-1; i++)		
		{
			floor[i][wid / 4 - 1] = 0;
			floor[i][wid / 4 - 2] = 0;
			floor[i][wid / 4 * 3] = 0;
			floor[i][wid / 4 * 3 + 1] = 0;
		}
	} else {
		for (int i = 1; i < len-1; i++)		
		{
			floor[i][wid / 4 - 1] = 0;
			floor[i][wid / 4 - 2] = 0;
			floor[i][wid / 4 * 3 + 1] = 0;
			floor[i][wid / 4 * 3 + 2] = 0;
		}
	}

	if (len % 2 == 0)							//�������� "������"
	{
		for (int j = 1; j < wid-1; j++)			
		{
			floor[len / 4 - 1][j] = 0;
			floor[len / 4 - 2][j] = 0;
			floor[len / 4 * 3][j] = 0;
			floor[len / 4 * 3 + 1][j] = 0;
		}
	} else {
		for (int j = 1; j < wid-1; j++)			
		{
			floor[len / 4 - 1][j] = 0;
			floor[len / 4 - 2][j] = 0;
			floor[len / 4 * 3 + 1][j] = 0;
			floor[len / 4 * 3 + 2][j] = 0;
		}
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
			if (floor[i][j] != 1)
			{
				floor[i][j] = 7;
			}
		}
	}
}

int shop::move(int r)			//�������, ����������� ����������� �����������
{
	if (r == 1)
		return 1;
	if (r == 7)
		return 7;
	return 0;
}

//�������, ����������� ����� � ��������� ����� �����
void shop::setBonus ()
{
	if (bonusCount < 15)
	{
		srand(time(0));
		int b = (rand() % 2 + 1); //13 5
		if (b == 2)
		{
			int i = (rand() % (len - 3) + 2);
			int j = (rand() % (wid - 3) + 2);
			if (floor[i][j] != 1 && floor[i][j] != 2 && floor[i][j] != 7)
			{
				floor[i][j] = 7;
				bonusCount += 1;
			}
		}
	}
}

//�����
void shop::f_out()				//����� ��������
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	s1 = 2;
	s2 = wid / 2;
	floor[s1][s2] = 2; 
	happiness = 0;
	while (moveKeys != 27)
	{
		setBonus();
		system("cls");	
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\n\n\tYour happiness: " << happiness << "\n\n";
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < wid; j++)
			{
				if (floor[i][j] == 1)
				{
					// ������� ��� ���� ������ (����� �������� 219 � ������� ����) � �������
					cout << static_cast<char>(219);
				}
				if (floor[i][j] == 0)
				{
					cout << " ";
				}
				if (floor[i][j] == 2)
				{
					SetConsoleTextAttribute(hConsole, 2);
					cout << "*";
					SetConsoleTextAttribute(hConsole, 15);
				}
				if (floor[i][j] == 7)
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
		if (moveKeys == 72)				//���� ������� �����
		{
			// �����
			if (move(floor[s1 - 1][s2]) != 1)
			{
				if (floor[s1 - 1][s2] == 7)
				{
					bonusCount-=1;
					happiness+=100;
				}
				floor[s1][s2] = 0;
				s1--;
				floor[s1][s2] = 2;
			}
		}
		if (moveKeys == 80)				//���� ������� ����
		{
			// ����
			if (move(floor[s1 + 1][s2]) != 1)
			{
				if (floor[s1 + 1][s2] == 7)
				{
					bonusCount-=1;
					happiness+=100;
				}
				floor[s1][s2] = 0;
				s1++;
				floor[s1][s2] = 2;
			}
		}
		if (moveKeys == 77)				//���� ������� ������
		{
			// ������
			if (move(floor[s1][s2 + 1]) != 1)
			{
				if (floor[s1][s2 + 1] == 7)
				{
					bonusCount-=1;
					happiness+=100;
				}
				floor[s1][s2] = 0;
				s2++;
				floor[s1][s2] = 2;
			}
		}
		if (moveKeys == 75)				//���� ������� �����
		{
			// �����
			if (move(floor[s1][s2 - 1]) != 1)
			{
				if (floor[s1][s2 - 1] == 7)
				{
					bonusCount-=1;
					happiness+=100;
				}
				floor[s1][s2] = 0;
				s2--;
				floor[s1][s2] = 2;
			}
		}
	}		//���� ��������, ���� �� �������� es�
	system("cls");
	cout << "\n\n\n\t\t\t    TOTAL happiness: " << happiness;
	cout << "\n\n\t\t\t\t GAME OVER\n" << endl;
}

//����������
shop::~shop()					//������� ��������� ������
{
	for( int i = 0; i < len; i++ )
		delete [] floor[i];
	delete [] floor;	
}
