#include "stdafx.h"

class Zolw : public Zwierze
{
public:
	Zolw(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat);
	Zolw(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat*swiat);
	~Zolw();
	void MakeChild(int pozycjaX, int pozycjaY) override;
	std::pair<int, int> czyAkcja() override;
	bool CzyOdbil(Organizm &organizm) override;
};