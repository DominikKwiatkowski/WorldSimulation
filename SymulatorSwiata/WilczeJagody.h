#include "stdafx.h"

class WilczeJagody : public Roslina
{
public:
	WilczeJagody(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat);
	~WilczeJagody();
	void MakeChild(int pozycjaX, int pozycjaY) override;
	void Kolizja(Organizm& wrog, bool atakujacy)override;
};