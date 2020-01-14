#include "stdafx.h"
class Roslina : public Organizm
{
public:
	Roslina(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat* swiat, char literka);
	virtual void Akcja();
	virtual void Kolizja(Organizm& wrog, bool atakujacy) override;
	virtual std::pair<int,int> czyAkcja() override;
	virtual void MakeChild(int pozycjaX, int pozycjaY) = 0;
	virtual ~Roslina();
};