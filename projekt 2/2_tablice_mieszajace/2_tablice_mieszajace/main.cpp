#include <algorithm>
#include <locale>
#include <ctime>
#include <iostream>
#include <cstdint>
#include "naglowki.h"

using namespace std;

int main(int argc, char**argv)
{
	setlocale(LC_ALL, "polish");			// ustawianie polskiego jêzyka
	srand(time(NULL));
	clock_t start, stop, pomiar;
	clock_t start2, stop2, pomiar2;
	cout.precision(7);						// zwiêkszenie miejsca po przecinku
	cout.setf(std::ios_base::fixed);

	int rozmiar = 1048576;
	int* tab_miesz = new int[rozmiar];		// tablica mieszaj¹ca
	wypelnij_pusta(tab_miesz, rozmiar);

	int rozmiar_dane = 10000000;
	int*dane = new int[rozmiar_dane];		// tablica, z której bêd¹ brane liczby do tablicy mieszaj¹cej
	wypelnij_i_mieszaj(dane, rozmiar_dane);	

	int licznik_zapelnienie = 0;	

	for (int i = 0; i < 10; i++)
	{
		double srednia = 0;
		double srednia2 = 0;
		int licznik_f_miesz_wstaw = 0;
		int licznik_f_miesz_szukaj = 0;
		zapelnienie(tab_miesz, dane, rozmiar, i, licznik_zapelnienie);
		int wartownik = licznik_zapelnienie + 10000;

		if (licznik_zapelnienie != 0)
		{
			for (int j = 0; j < 10000; j++)											//szukanie
			{
				int32_t r = ((rand() & 0x7FFF) << 15) | (rand() & 0x7FFF);
				r = r % licznik_zapelnienie;
				start2 = clock();
				szukaj(tab_miesz, rozmiar, dane[r], licznik_f_miesz_szukaj);
				stop2 = clock();
				pomiar2 = stop2 - start2;
				srednia2 += pomiar2 / (double)CLOCKS_PER_SEC;
			}
			srednia2 /= 10000;
		}
		
		for (licznik_zapelnienie; licznik_zapelnienie < wartownik; licznik_zapelnienie++)	//wstawianie
		{
			start = clock();
			wstaw(tab_miesz, rozmiar, dane[licznik_zapelnienie], licznik_f_miesz_wstaw);
			stop = clock();
			pomiar = stop - start;
			srednia += pomiar / (double)CLOCKS_PER_SEC;
		}
		srednia /= 10000;

		cout << "Wype³nienie tablicy: " << i*10 << "% \n";
		cout << "Œredni czas wyszukiwania elementu: " << srednia2 << "s" << endl;
		cout << "Iloœæ wywo³añ funkcji mieszaj¹cej dla szukania: " << licznik_f_miesz_szukaj << endl << endl;

		cout << "Œredni czas wstawiania elementu: " << srednia << "s" << endl;
		cout << "Iloœæ wywo³añ funkcji mieszaj¹cej dla wstawiania: " << licznik_f_miesz_wstaw << endl << endl << endl;

		//cout  << i * 10 << "%\t"<< srednia2 << "\t" << licznik_f_miesz_szukaj <<"\t" << srednia << "\t" << licznik_f_miesz_wstaw << endl;
		
	}
	
	delete[] tab_miesz;
	delete[] dane;
}