#include "stdafx.h"

class Lis : public Zwierze
{
public:
	Lis(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat);
	Lis(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat*swiat);
	~Lis();
	virtual void MakeChild(int pozycjaX, int pozycjaY) override;
	virtual std::pair<int, int> czyAkcja() override;
};