#include <algorithm>
#include <ctime>
#include <iostream>
#include "naglowki.h"

using namespace std;

void wypelnij(int*tab, int rozmiar)
{
	for (int i = 0;i < rozmiar;i++)
	{
		tab[i] = i+1;
	}
}

void wyswietl(int*tab, int rozmiar)
{
	for (int i = 0;i < rozmiar;i++)
	{
		cout << tab[i]<<std::endl;
	}
	cout << std::endl;
}


void sort_babelkowe(int*tab, int rozmiar)
{
	for (int i = 0;i < rozmiar;i++)
	{
		for (int j = 1;j < rozmiar;j++)
		{
			if (tab[j - 1] > tab[j])
				swap(tab[j - 1],tab[j]);
		}
	}
}

bool test(int*tab, int rozmiar)
{
	for (int i = 1; i < rozmiar; i++)
	{
		if (tab[i] < tab[i - 1])
			return 0;
	}
	return 1;
}

void sort_wstawianie(int*tab, int rozmiar)
{
	for (int i = 1; i < rozmiar; i++)
	{
		int x = tab[i];
		int j = i - 1;
		while (j >= 0 && x < tab[j])
		{
			tab[j + 1] = tab[j];
			j = j - 1;
		}
		tab[j + 1] = x;
	}
}

void sort_wybieranie(int*tab, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		int k = i;
		int x = tab[i];

		for (int j = i; j <= rozmiar; j++)
		{
			if (tab[j] < x)
			{
				k = j;
				x = tab[j];
			}
		}
		tab[k] = tab[i];
		tab[i] = x;
	}
}

void sort_shell(int*tab, int rozmiar)
{
	int h = 1;
	while (h < rozmiar / 9)
	{
		h = 3 * h + 1;
	}
	while (h > 0)
	{
		for (int i = h ; i < rozmiar; i++)
		{
			int x = tab[i];
			int j = i;
			while (j >= h  && x < tab[j - h])
			{
				tab[j] = tab[j - h];
				j = j - h;
			}
			tab[j] = x;
		}
		h = h / 3;
	}
}

void sort_szybkie(int*tab, int d, int g)
{
	if (d < g)
	{
		int t = tab[d];
		int s = d;
		for (int i = d; i <= g; i++)
		{
			if (tab[i] < t)
			{
				s = s + 1;
				swap(tab[s], tab[i]);
			}
		}
		swap(tab[d], tab[s]);
		sort_szybkie(tab, d, s - 1);
		sort_szybkie(tab, s + 1, g);
	}
}

void sort_szybkie_mediana(int*tab, int d, int g)
{
	if (d < g)
	{
		int s1 = d;
		int s2 = g;
		int s3 = (d+g)/2;

		int t1 = tab[s1];
		int t2 = tab[s2];
		int t3 = tab[s3];

		if (t3 > t2)
		{
			if (t2 > t1)
				swap(tab[s2], tab[d]);
			else if (t3 > t1)
				swap(tab[s1], tab[d]);
			else
				swap(tab[s3], tab[d]);
		}
		else	//t3<t2
		{
			if (t2<t1)
				swap(tab[s2], tab[d]);
			else if (t3 < t1)
				swap(tab[s1], tab[d]);
			else
				swap(tab[s3], tab[d]);
		}		

		int t = tab[d];
		int s = d;
		for (int i = d; i <= g; i++)
		{
			if (tab[i] < t)
			{
				s = s + 1;
				swap(tab[s], tab[i]);
			}
		}
		swap(tab[d], tab[s]);
		sort_szybkie_mediana(tab, d, s - 1);
		sort_szybkie_mediana(tab, s + 1, g);
	}
}

void sort_szybkie_wstaw(int*tab, int d, int g)
{
	if (d < g)
	{
		if (g - d < 20)
		{
			for (int i = d; i <= g; i++)
			{
				int x = tab[i];
				int j = i - 1;
				while (j >= d && x < tab[j])
				{
					tab[j + 1] = tab[j];
					j = j - 1;
				}
				tab[j + 1] = x;
			}
			return;
		}

		int t = tab[d];
		int s = d;
		for (int i = d; i <= g; i++)
		{
			if (tab[i] < t)
			{
				s = s + 1;
				swap(tab[s], tab[i]);
			}
		}
		swap(tab[d], tab[s]);
		sort_szybkie_wstaw(tab, d, s - 1);
		sort_szybkie_wstaw(tab, s + 1, g);
	}
}