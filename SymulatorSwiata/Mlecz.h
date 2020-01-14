#include "stdafx.h"

class Mlecz : public Roslina
{
public:
	Mlecz(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat);
	~Mlecz();
	void MakeChild(int pozycjaX, int pozycjaY) override;
	void Akcja() override;
};