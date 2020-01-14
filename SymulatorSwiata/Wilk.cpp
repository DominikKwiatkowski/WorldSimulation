#include "stdafx.h"

Wilk::Wilk(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat)
:Zwierze(dataUrodzenia, 9, 5, pozycjaX, pozycjaY, swiat, 'w')
{
}
Wilk::Wilk(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat*swiat)
: Zwierze(dataUrodzenia, sila, 5, pozycjaX, pozycjaY, swiat, 'w')
{
}
Wilk::~Wilk()
{
	swiat->Usun(*this);
}
void Wilk::MakeChild(int pozycjaX, int pozycjaY)
{
	new Wilk(swiat->GetIloscTur(), pozycjaX, pozycjaY, swiat);
}