#include "stdafx.h"

Owca::Owca(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat)
:Zwierze(dataUrodzenia, 4, 4, pozycjaX, pozycjaY, swiat, 'o')
{
}
Owca::Owca(int dataUrodzenia,int sila, int pozycjaX, int pozycjaY, Swiat*swiat)
: Zwierze(dataUrodzenia, sila, 4, pozycjaX, pozycjaY, swiat, 'o')
{
}
Owca::~Owca()
{
	swiat->Usun(*this);
}
void Owca::MakeChild(int pozycjaX, int pozycjaY)
{
	new Owca(swiat->GetIloscTur(), pozycjaX, pozycjaY, swiat);
}