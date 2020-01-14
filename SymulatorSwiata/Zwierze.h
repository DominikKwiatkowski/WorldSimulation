#include "stdafx.h"
class Zwierze : public Organizm
{
public:
	Zwierze(int dataUrodzenia, int sila,int inicjatywa, int pozycjaX, int pozycjaY, Swiat* swiat, char literka);
	virtual void Akcja() override;
	virtual void Kolizja(Organizm& wrog, bool atakujacy) override;
	virtual std::pair<int, int> czyAkcja() override;
	virtual void MakeChild(int pozycjaX, int pozycjaY) = 0;
	virtual bool CzyOdbil(Organizm &organizm);
	bool CzyZwierze() override;
	virtual ~Zwierze();
};