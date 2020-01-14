#include "stdafx.h"

WilczeJagody::WilczeJagody(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat)
:Roslina(dataUrodzenia, 99, pozycjaX, pozycjaY, swiat, 'j')
{
	SetTrujaca(true);
}
WilczeJagody::~WilczeJagody()
{
	swiat->Usun(*this);
}
void WilczeJagody::MakeChild(int pozycjaX, int pozycjaY)
{
	new WilczeJagody(swiat->GetIloscTur(), pozycjaX, pozycjaY, swiat);
}
void WilczeJagody::Kolizja(Organizm& wrog, bool atakujacy)
{
	GetSwiat()->SetMapa(wrog.GetPozycjaX(), wrog.GetPozycjaY(), NULL);
	GetSwiat()->SetMapa(GetPozycjaX(), GetPozycjaY(), NULL);
	if (GetSila() > wrog.GetSila())
	{
		delete this;
	}
	delete &wrog;
}