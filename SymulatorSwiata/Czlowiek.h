#include "stdafx.h"

class Czlowiek : public Zwierze
{
private:
	int ruch;
	int umSpec=-5;
	void SpalWszystko();
public:
	Czlowiek(int pozycjaX, int pozycjaY, Swiat*swiat);
	Czlowiek(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat*swiat);
	~Czlowiek();
	void MakeChild(int pozycjaX, int pozycjaY) override;
	void Akcja() override;
	void SetRuch(int ruch);
	int GetRuch() const;
	void SetSpec(); 
	int GetSpec() const;
};