#include "stdafx.h"

Zolw::Zolw(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat)
:Zwierze(dataUrodzenia, 2, 1, pozycjaX, pozycjaY, swiat, 'z')
{
}
Zolw::Zolw(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat*swiat)
: Zwierze(dataUrodzenia, sila, 1, pozycjaX, pozycjaY, swiat, 'z')
{
}
Zolw::~Zolw()
{
	swiat->Usun(*this);
}
void Zolw::MakeChild(int pozycjaX, int pozycjaY)
{
	new Zolw(swiat->GetIloscTur(), pozycjaX, pozycjaY, swiat);
}
std::pair<int, int> Zolw::czyAkcja()
{
	if (!(rand() % 4))
	{
		return Zwierze::czyAkcja();
	}
	return std::pair<int, int>(-1, -1);
}
bool Zolw::CzyOdbil(Organizm &organizm)
{
	if (organizm.GetSila() < 5)
	{
		return true;
	}
	return false;
}