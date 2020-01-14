#include "stdafx.h"

class Owca : public Zwierze
{
public:
	Owca(int dataUrodzenia, int pozycjaX, int pozycjaY, Swiat*swiat);
	Owca(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat*swiat);
	~Owca();
	void MakeChild(int pozycjaX, int pozycjaY) override;
};