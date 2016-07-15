#include <algorithm>
#include <locale>
#include <ctime>
#include <iostream>
#include <cstdint>
#include "naglowki.h"

using namespace std;

void wypelnij_pusta(int*tab, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = -1;
	}
}

void wypelnij_i_mieszaj(int*tab, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = i;
	}
	random_shuffle(tab, tab + rozmiar);
}

bool wstaw(int*tab, int rozmiar, int element, int& licznik)
{
	for (int i = 0; i < rozmiar; i++)
	{
		int k = f_mieszajaca(rozmiar, element, i);
		//int k = f_mieszajaca2(rozmiar, element, i);
		licznik += 1;
		if (tab[k] == -1)
		{
			tab[k] = element;
			return true;
		}
	}
	return false;
}

bool wstaw(int*tab, int rozmiar, int element)		//przeci¹¿enie funkcji (mo¿na j¹ wywo³aæ na dwojaki sposób: z licznikiem lub bez)
{
	for (int i = 0; i < rozmiar; i++)
	{
		int k = f_mieszajaca(rozmiar, element, i);
		//int k = f_mieszajaca2(rozmiar, element, i);
		if (tab[k] == -1)
		{
			tab[k] = element;
			return true;
		}
	}
	return false;
}

int f_mieszajaca(int rozmiar, int x, int i)
{
	if (i == 0)
		return x % rozmiar;
	else
		return (f_mieszajaca(rozmiar,x, 0) + i) % rozmiar;
}

void zapelnienie(int* tab_miesz, int*dane, int rozmiar, int mnoznik, int& licznik)
{
	int i = (rozmiar / 10) * mnoznik;
	for (licznik; licznik < i; licznik++)
	{
		wstaw(tab_miesz, rozmiar, dane[licznik]);
	}
}

bool szukaj(int*tab, int rozmiar, int element, int& licznik)
{
	for (int i = 0; i < rozmiar; i++)
	{
		int k = f_mieszajaca(rozmiar, element, i);
		//int k = f_mieszajaca2(rozmiar, element, i);
		licznik += 1;
		if (tab[k] == element)
			return true;
		if (tab[k] == -1)
			return false;
	}
	return false;
}

int f_mieszajaca2(int rozmiar, int x, int i)
{
	return ((x % rozmiar) + i*((((x / rozmiar) % (rozmiar / 2)) * 2) + 1)) % rozmiar;
}

