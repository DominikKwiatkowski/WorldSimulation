#include "stdafx.h"

Czlowiek::Czlowiek(int pozycjaX, int pozycjaY, Swiat*swiat)
:Zwierze(0, 4, 4, pozycjaX, pozycjaY, swiat, 'H')
{
}
Czlowiek::Czlowiek(int dataUrodzenia, int sila, int pozycjaX, int pozycjaY, Swiat*swiat)
: Zwierze(dataUrodzenia, sila, 4, pozycjaX, pozycjaY, swiat, 'H')
{
}
Czlowiek::~Czlowiek()
{
	swiat->Usun(*this);
}
void Czlowiek::MakeChild(int pozycjaX, int pozycjaY)
{
}
void Czlowiek::SpalWszystko()
{
	std::vector<std::pair<int, int>> tab = swiat->GetSasiadow(GetPozycjaX(), GetPozycjaY());
	for (int i = 0; i < tab.size(); i++)
	{
		if (tab[i].first >= 0 && GetSwiat()->GetMapa()[tab[i].first][tab[i].second] != NULL)
		{
			GetSwiat()->GetLog()->Spalenie(*GetSwiat()->GetMapa()[tab[i].first][tab[i].second]);
			delete GetSwiat()->GetMapa()[tab[i].first][tab[i].second];
			GetSwiat()->SetMapa(tab[i].first, tab[i].second, NULL);
		}
	}
}
void Czlowiek::Akcja()
{
	if (GetSpec() > 0)
		SpalWszystko();
	char input;
	cout << *(this->GetSwiat());
	input = _getch();
	if (input == 'e')
	{
		this->SetSpec();
	}
	while(input != -32)//dopoki nie zostanie wcisnieta jakas strzalka
	{
		input = _getch();
	}
	input = _getch();
	if (input == 0x48)
		this->SetRuch(UP);
	else if (input == 0x50)
		this->SetRuch(DOWN);
	else if (input == 0x4b)
		this->SetRuch(LEFT);
	else if (input == 0x4d)
		this->SetRuch(RIGHT);
	pair<int, int> pozycje;
	pozycje.first = this->GetPozycjaX();
	pozycje.second = this->GetPozycjaY();
	switch (ruch)
	{
	case UP:
		if (this->GetPozycjaX() > 0)
			pozycje.first -= 1;
		break;
	case DOWN:
		if (this->GetPozycjaX() < this->GetSwiat()->GetDlugosc()-1)
			pozycje.first += 1;
		break;
	case LEFT:
		if (this->GetPozycjaY() > 0)
			pozycje.second -= 1;
		break;
	case RIGHT:
		if (this->GetPozycjaY() < this->GetSwiat()->GetSzerokosc() - 1)
			pozycje.second += 1;
		break;
	}
	if (swiat->GetMapa()[pozycje.first][pozycje.second] == NULL)
	{
		this->GetSwiat()->SetMapa(GetPozycjaX(), GetPozycjaY(), NULL);
		this->SetPozycjaX(pozycje.first);
		this->SetPozycjaY(pozycje.second);
		this->GetSwiat()->SetMapa(GetPozycjaX(), GetPozycjaY(), this);
	}
	else
	{
		Kolizja(*swiat->GetMapa()[pozycje.first][pozycje.second], true);
	}
	if (GetSpec() > 0)
		SpalWszystko();
	umSpec--;
}
void Czlowiek::SetRuch(int ruch)
{
	this->ruch = ruch;
}
int Czlowiek::GetRuch()const
{
	return ruch;
}
void Czlowiek::SetSpec()
{
	if (umSpec <= -4)
		umSpec = 5;
}
int Czlowiek::GetSpec() const
{
	return umSpec;
}