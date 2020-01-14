#include "stdafx.h"

Mlecz::Mlecz(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat)
:Roslina(dataUrodzenia, 0, pozycjaX, pozycjaY, swiat, 'm')
{
}
Mlecz::~Mlecz()
{
	swiat->Usun(*this);
}
void Mlecz::MakeChild(int pozycjaX, int pozycjaY)
{
	new Mlecz(swiat->GetIloscTur(), pozycjaX, pozycjaY, swiat);
}
void Mlecz::Akcja()
{
	for (int i = 0; i < 3; i++)
	{
		Roslina::Akcja();
	}
}
