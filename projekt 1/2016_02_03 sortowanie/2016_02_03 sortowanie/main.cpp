#include <algorithm>
#include <ctime>
#include <iostream>
#include "naglowki.h"

using namespace std;

int main(int argc, char**argv)
{
	int rozmiar = 1000;
	int proby = 5;
	float srednia = 0;
	std::srand(time(NULL));
	
	while (srednia < 30)
	{
		srednia = 0;
		int *tab = new int[rozmiar];
		clock_t start, stop, pomiar;
		wypelnij(tab, rozmiar);

		for (int i = 0; i < proby; i++)
		{
			std::random_shuffle(tab, tab + rozmiar);
			start = clock();
			//sort_babelkowe(tab, rozmiar);
			//sort_wstawianie(tab, rozmiar);
			//sort_wybieranie(tab, rozmiar);
			//sort_shell(tab, rozmiar);
			//sort_szybkie(tab, 0, rozmiar - 1);
			//sort_szybkie_mediana(tab, 0, rozmiar - 1);
			sort_szybkie_wstaw(tab, 0, rozmiar - 1);
			stop = clock();
			if (test(tab, rozmiar) == false)
			{
				cout << "Tablica nieposortowana, program sie zakonczyl.\n";
				delete[] tab;
				return 0;
			}
			pomiar = stop - start;
			srednia += pomiar / (float)CLOCKS_PER_SEC;
		}
		srednia = srednia / proby;
		std::cout << "Srednia dla " << rozmiar << " elementow tablicy: " << srednia << "s" << endl;
		rozmiar = rozmiar * 2;
		delete[] tab;
	}
}