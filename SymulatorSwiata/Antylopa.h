#include "stdafx.h"

class Antylopa : public Zwierze
{
public:
	Antylopa(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat);
	Antylopa(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat*swiat);
	~Antylopa();
	void MakeChild(int pozycjaX, int pozycjaY) override;
	void Akcja() override;
	bool CzyZwial() override;
};