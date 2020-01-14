#include "stdafx.h"

Organizm::Organizm(int dataUrodzenia, int sila, int inicjatywa, int pozycjaX, int pozycjaY, Swiat* swiat, char literka)
:dataUrodzenia(dataUrodzenia), sila(sila), inicjatywa(inicjatywa), pozycjaX(pozycjaX), pozycjaY(pozycjaY), swiat(swiat), literka(literka)
{
	swiat->SetMapa(pozycjaX, pozycjaY, this);
	swiat->Dodaj(*this);
}
std::ostream& operator<<(std::ostream& os, const Organizm& organizm) {
	organizm.Wypisz(os);
	return os;
}
void Organizm::Wypisz(std::ostream& out)const
{
	out << literka;
}
int Organizm::GetDataUrodzenia() const
{
	return dataUrodzenia;
}
int Organizm::GetInicjatywa() const
{
	return inicjatywa;
}
int Organizm::GetPozycjaX() const
{
	return pozycjaX;
}
int Organizm::GetPozycjaY() const
{
	return pozycjaY;
}
int Organizm::GetSila() const
{
	return sila;
}
Swiat* Organizm::GetSwiat() const
{
	return swiat;
}
void Organizm::SetDataUrodznie(int dataUrodzenia)
{
	this->dataUrodzenia = dataUrodzenia;
}
void Organizm::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
void Organizm::SetPozycjaX(int pozycjaX)
{
	this->pozycjaX = pozycjaX;
}
void Organizm::SetPozycjaY(int pozycjaY)
{
	this->pozycjaY = pozycjaY;
}
void Organizm::SetSila(int sila)
{
	this->sila = sila;
}
void Organizm::SetSwiat(Swiat* swiat)
{
	this->swiat = swiat;
}
bool Organizm::CzyOdbil(Organizm &organizm)
{
	return false;
}
Organizm::~Organizm()
{ 
}
char Organizm::GetLiterka() const
{
	return literka;
}
void Organizm::SetTrujaca(bool value)
{
	trujaca = value;
}
bool Organizm::GetTrujaca() const
{
	return trujaca;
}
std::ostream& operator<<(std::ostream& out, Organizm& o)
{
	out << o.GetLiterka();
	return out;
}
bool Organizm::CzyZwial()
{
	return false;
}
bool Organizm::CzyZwierze()
{
	return false;
}