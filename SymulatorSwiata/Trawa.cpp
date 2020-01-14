#include "stdafx.h"

Trawa::Trawa(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat)
:Roslina(dataUrodzenia, 0, pozycjaX, pozycjaY, swiat, 't')
{
}
Trawa::~Trawa()
{
	swiat->Usun(*this);
}
void Trawa::MakeChild(int pozycjaX, int pozycjaY)
{
	new Trawa(swiat->GetIloscTur(), pozycjaX, pozycjaY, swiat);
}