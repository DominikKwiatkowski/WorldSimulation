#include "stdafx.h"

BarszczSosnowskiego::BarszczSosnowskiego(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat)
:Roslina(dataUrodzenia, 10, pozycjaX, pozycjaY, swiat, 'b')
{
	SetTrujaca(true);
}
BarszczSosnowskiego::~BarszczSosnowskiego()
{
	swiat->Usun(*this);
}
void BarszczSosnowskiego::MakeChild(int pozycjaX, int pozycjaY)
{
	new BarszczSosnowskiego(swiat->GetIloscTur(), pozycjaX, pozycjaY, swiat);
}
void BarszczSosnowskiego::Kolizja(Organizm& wrog, bool atakujacy)
{
	GetSwiat()->SetMapa(wrog.GetPozycjaX(), wrog.GetPozycjaY(), NULL);
	GetSwiat()->SetMapa(GetPozycjaX(), GetPozycjaY(), NULL);
	if (GetSila() > wrog.GetSila())
	{
		delete this;
	}
	delete &wrog;
}
void BarszczSosnowskiego::Akcja()
{
	std::vector<std::pair<int, int>> tab = swiat->GetSasiadow(GetPozycjaX(), GetPozycjaY());
	for (int i = 0; i < tab.size(); i++)
	{
		if (tab[i].first >= 0 && GetSwiat()->GetMapa()[tab[i].first][tab[i].second] != NULL && GetSwiat()->GetMapa()[tab[i].first][tab[i].second]->CzyZwierze())
		{
			GetSwiat()->GetLog()->Barszczowanie(*GetSwiat()->GetMapa()[tab[i].first][tab[i].second]);
			delete GetSwiat()->GetMapa()[tab[i].first][tab[i].second];
			GetSwiat()->SetMapa(tab[i].first, tab[i].second, NULL);
		}
	}
	Roslina::Akcja();
}