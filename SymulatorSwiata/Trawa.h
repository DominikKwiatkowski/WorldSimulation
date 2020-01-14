#include "stdafx.h"

class Trawa : public Roslina
{
public:
	Trawa(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat);
	~Trawa();
	void MakeChild(int pozycjaX, int pozycjaY) override;
};