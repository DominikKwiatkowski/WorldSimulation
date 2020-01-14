// SymulatorSwiata.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
int main()
{
	srand(time(NULL));
	char sterowanie = 1;
	int dlugosc, szerokosc;
	cin >> dlugosc >> szerokosc;
	Swiat swiat(dlugosc, szerokosc);
	new Czlowiek(dlugosc / 2, szerokosc / 2, &swiat);
	for (int i = 0; i < 3; i++)
	{
		new Wilk(swiat.GetIloscTur(), i * 3, i * 2, &swiat);
		new Trawa(swiat.GetIloscTur(), i * 2 + 2, i * 3 + 3, &swiat);
		new Owca(swiat.GetIloscTur(), 0 , i + 3, &swiat);
		new Lis(swiat.GetIloscTur(), i + 5, i, &swiat);
		new Zolw(swiat.GetIloscTur(), i + 8, i + 8, &swiat);
		new Antylopa(swiat.GetIloscTur(), i , i + 10, &swiat);
		new Mlecz(swiat.GetIloscTur(), i + 15, i + 10, &swiat);
		new Guarana(swiat.GetIloscTur(), i + 10, i + 15, &swiat);
		new WilczeJagody(swiat.GetIloscTur(), i + 18, i + 15, &swiat);
		new BarszczSosnowskiego(swiat.GetIloscTur(), i + 15, i + 18, &swiat);
	}
	while (sterowanie!='q')
	{
		cout << swiat;
		swiat.PrzeprowadzTure();
		cout << swiat;
		cout << endl << "Koniec tury, wcisnij q aby wyjsc,s zeby zapisac, l wczytac, lub inna literke aby kontynuowac";
		sterowanie = _getch();
		if (sterowanie == 's')
		{
			swiat.Zapisz();
		}
		else if (sterowanie == 'l')
		{
			swiat.Wczytaj();
		}
	}
	return 0;
}

