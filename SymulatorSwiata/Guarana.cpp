#include "stdafx.h"

Guarana::Guarana(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat)
:Roslina(dataUrodzenia, 0, pozycjaX, pozycjaY, swiat, 'g')
{
}
Guarana::~Guarana()
{
	swiat->Usun(*this);
}
void Guarana::MakeChild(int pozycjaX, int pozycjaY)
{
	new Guarana(swiat->GetIloscTur(), pozycjaX, pozycjaY, swiat);
}
void Guarana::Kolizja(Organizm& wrog, bool atakujacy)
{
	wrog.SetSila(wrog.GetSila() + 3);
}