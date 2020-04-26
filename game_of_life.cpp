#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	int min = 1;
	int max = 100;
	if ((rand() % (max - min + 1) + min) <= 25)
	{
		return true;
	}
	return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j] == true)
	{
		return true;
	}
	return false;
}

game_of_life::game_of_life()
{
}

void game_of_life::sljedeca_generacija()
{

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int count = 0;
			if (celija_zauzeta(i - 1, j - 1) && ((i - 1) >= 0) && ((j - 1) >= 0))
			{
				count++;
			}
			if (celija_zauzeta(i - 1, j) && ((i - 1) >= 0))
			{
				count++;
			}
			if (celija_zauzeta(i - 1, j + 1) && ((i - 1) >= 0) && ((j + 1) < 40))
			{
				count++;
			}
			if (celija_zauzeta(i, j - 1) && ((j - 1) >= 0))
			{
				count++;
			}
			if (celija_zauzeta(i, j + 1) && ((j + 1) < 40))
			{
				count++;
			}
			if (celija_zauzeta(i + 1, j - 1) && ((i + 1) < 40) && ((j - 1) >= 0))
			{
				count++;
			}
			if (celija_zauzeta(i + 1, j) && ((i + 1) < 40))
			{
				count++;
			}
			if (celija_zauzeta(i + 1, j + 1) && ((i + 1) < 40) && ((j + 1) < 40))
			{
				count++;
			}
			
			if (celija_zauzeta(i, j))
			{
				if (count == 3 || count == 2)
				{
					_sljedeca_generacija[i][j] = true;
				}
				else
				{
					_sljedeca_generacija[i][j] = false;
				}
			}
			else if (count == 3)
			{
				_sljedeca_generacija[i][j] = true;
			}
			else
			{
				_sljedeca_generacija[i][j] = false;
			}
		}
	}
	int num = sizeof(bool) * REDAKA * STUPACA;
	memcpy(_generacija, _sljedeca_generacija, num);
}

void game_of_life::iscrtaj()
{
	if (_generacija[0][0] == 204)
	{
		srand(time(nullptr));
		for (int i = 0; i < REDAKA; i++)
		{
			for (int j = 0; j < STUPACA; j++)
			{

				if (slucajna_vrijednost()) 
				{
					_generacija[i][j] = true;
					cout << "*";
				}
				else 
				{
					_generacija[i][j] = false;
					cout << "-";
				}
			}
			cout << endl;
		}
	}
	else 
	{
		for (int i = 0; i < REDAKA; i++)
		{
			for (int j = 0; j < STUPACA; j++)
			{
				if (_generacija[i][j])
				{
					cout << "*";
				}
				else
				{
					cout << "-";
				}
			}
			cout << endl;
		}
	}
}
