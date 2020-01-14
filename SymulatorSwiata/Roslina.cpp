#include "stdafx.h"

Roslina::Roslina(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat* swiat,char literka)
:Organizm(dataUrodzenia, sila, 0, pozycjaX, pozycjaY, swiat, literka)
{

}
void Roslina::Akcja()
{
	std::pair<int, int> pozycje = czyAkcja();
	if (pozycje.first == -1)
		return;
	else
	{
		MakeChild(pozycje.first, pozycje.second);
	}
}
std::pair<int,int> Roslina::czyAkcja()
{
	int numerx, numery;
	int numer = rand() % 10;
	if (numer < 2)
	{
		Organizm***mapa = GetSwiat()->GetMapa();
		for (int i = 0; i < 20;i++)
		{
			int numerx = rand() % 3;
			numerx += GetPozycjaX() - 1;
			int numery = rand() % 3;
			numery += GetPozycjaY() - 1;
			if (numerx >= 0 && numerx< swiat->GetDlugosc() && numery >= 0 && numery< swiat->GetSzerokosc() && mapa[numerx][numery] == NULL)
			{
				return std::pair<int, int>(numerx, numery);
			}
		}
	}
	return std::pair<int, int>(-1, -1);
}
void Roslina::Kolizja(Organizm& wrog, bool atakujacy)
{
	if (sila > wrog.GetSila())
	{
		GetSwiat()->SetMapa(wrog.GetPozycjaX(), wrog.GetPozycjaY(), NULL);
		delete &wrog;
	}
}
Roslina::~Roslina()
{
}