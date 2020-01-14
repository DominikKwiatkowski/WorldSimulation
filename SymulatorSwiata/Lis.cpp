#include "stdafx.h"

Lis::Lis(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat)
:Zwierze(dataUrodzenia, 3, 7, pozycjaX, pozycjaY, swiat, 'l')
{
}
Lis::Lis(int dataUrodzenia,int sila, int pozycjaX, int pozycjaY, Swiat*swiat)
: Zwierze(dataUrodzenia, sila, 7, pozycjaX, pozycjaY, swiat, 'l')
{
}
Lis::~Lis()
{
	swiat->Usun(*this);
}
void Lis::MakeChild(int pozycjaX, int pozycjaY)
{
	new Lis(swiat->GetIloscTur(), pozycjaX, pozycjaY, swiat);
}
std::pair<int, int> Lis::czyAkcja()
{
	std::vector<std::pair<int, int>> tab = swiat->GetSasiadow(this->GetPozycjaX(), this->GetPozycjaY());
	std::pair<int, int> wylosowano;
	wylosowano = std::pair<int, int>(-1, -1);
	for (int i = 0; i < 4; i++)
	{
		int numer = rand() % (4 - i);
		if (tab[numer].first == -1 || (GetSwiat()->GetMapa()[tab[numer].first][tab[numer].second]!=NULL &&(GetSwiat()->GetMapa()[tab[numer].first][tab[numer].second]->GetSila() > this->GetSila())))
		{
			std::swap(tab[3 - i], tab[numer]);
		}
		else
		{
			wylosowano = tab[numer];
			break;
		}
	}
	return wylosowano;
}