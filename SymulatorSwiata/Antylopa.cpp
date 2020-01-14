#include "stdafx.h"

Antylopa::Antylopa(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat)
:Zwierze(dataUrodzenia, 4, 4, pozycjaX, pozycjaY, swiat, 'a')
{
}
Antylopa::Antylopa(int dataUrodzenia,int sila, int pozycjaX, int pozycjaY, Swiat*swiat)
: Zwierze(dataUrodzenia, sila, 4, pozycjaX, pozycjaY, swiat, 'a')
{
}
Antylopa::~Antylopa()
{
	swiat->Usun(*this);
}
void Antylopa::MakeChild(int pozycjaX, int pozycjaY)
{
	new Antylopa(swiat->GetIloscTur(), pozycjaX, pozycjaY, swiat);
}
void Antylopa::Akcja()
{

	Zwierze::Akcja();
	if (this->literka == 'a')
		Zwierze::Akcja();
}
bool Antylopa::CzyZwial()
{
	
	if (rand()%2)//zwiewanie na sasiednie pole
	{
		std::vector<std::pair<int, int>> tab = swiat->GetSasiadow(this->GetPozycjaX(), this->GetPozycjaY());
		std::pair<int, int> wylosowano;
		wylosowano = std::pair<int, int>(-1, -1);
		for (int i = 0; i < 4; i++)
		{
			int numer = rand() % (4 - i);
			if (tab[numer].first == -1 || GetSwiat()->GetMapa()[tab[numer].first][tab[numer].second] != NULL)
			{
				std::swap(tab[3 - i], tab[numer]);
			}
			else
			{
				wylosowano = tab[numer];
				break;
			}
		}
		if (wylosowano.first == -1)
		{
			return false;
		}
		this->GetSwiat()->SetMapa(GetPozycjaX(), GetPozycjaY(), NULL);
		this->SetPozycjaX(wylosowano.first);
		this->SetPozycjaY(wylosowano.second);
		this->GetSwiat()->SetMapa(GetPozycjaX(), GetPozycjaY(), this);
		return true;
	}
	return false;
}