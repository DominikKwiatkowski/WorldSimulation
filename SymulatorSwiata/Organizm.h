#include "stdafx.h"
#ifndef SWIAT_H
#define SWIAT_H
class Swiat;
class Organizm
{
protected:
	int dataUrodzenia;
	int sila;
	int inicjatywa;
	int pozycjaX;
	int pozycjaY;
	char literka;
	Swiat *swiat;
	bool trujaca=false;
protected:
	friend std::ostream& operator<<(std::ostream& os, const Organizm& organizm);
	void Wypisz(std::ostream& out) const;
	virtual std::pair<int, int> czyAkcja() = 0;
public:
	Organizm(int dataUrodzenia, int sila, int inicjatywa, int pozycjaX, int pozycjaY, Swiat* swiat, char literka);
	 int GetDataUrodzenia() const;
	 void SetDataUrodznie(int dataUrodzenia);
	 int GetSila()const;
	 void SetSila(int sila);
	 int GetInicjatywa() const;
	 void SetInicjatywa(int inicjatywa);
	 int GetPozycjaX() const;
	 void SetPozycjaX(int pozycjaX);
	 int GetPozycjaY() const;
	 void SetPozycjaY(int pozycjaY);
	 Swiat* GetSwiat() const;
	 void SetSwiat(Swiat* swiat);
	 virtual void Akcja()=0;
	 char GetLiterka()const;
	 virtual void MakeChild(int pozycjaX, int pozycjaY) = 0;
	 virtual bool CzyZwial();
	 virtual void Kolizja(Organizm& wrog, bool atakujacy) = 0;
	 bool CzyOdbil(Organizm &organizm);
	 virtual bool CzyZwierze();
	 bool GetTrujaca() const;
	 void SetTrujaca(bool value);
	 virtual ~Organizm();
};
#endif