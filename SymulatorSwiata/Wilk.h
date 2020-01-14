#include "stdafx.h"

class Wilk : public Zwierze
{
public:
	Wilk(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat);
	Wilk(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat*swiat);
	~Wilk();
	void MakeChild(int pozycjaX, int pozycjaY) override;
};