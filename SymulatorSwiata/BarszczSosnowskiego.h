#include "stdafx.h"

class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat);
	~BarszczSosnowskiego();
	void MakeChild(int pozycjaX, int pozycjaY) override;
	void Kolizja(Organizm& wrog, bool atakujacy)override;
	void Akcja() override;
};