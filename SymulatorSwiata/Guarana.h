#include "stdafx.h"

class Guarana : public Roslina
{
public:
	Guarana(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat);
	~Guarana();
	void MakeChild(int pozycjaX, int pozycjaY) override;
	void Kolizja(Organizm& wrog, bool atakujacy)override;
};