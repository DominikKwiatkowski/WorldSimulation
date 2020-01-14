#include "stdafx.h"
Zwierze::Zwierze(int dataUrodzenia, int sila, int inicjatywa, int pozycjaX, int pozycjaY, Swiat* swiat, char literka)
:Organizm(dataUrodzenia, sila, inicjatywa, pozycjaX, pozycjaY, swiat, literka)
{}
void Zwierze::Kolizja(Organizm& wrog, bool atakujacy)
{
	if (this->GetLiterka() == wrog.GetLiterka())
	{
		int pozx = GetPozycjaX(), pozy = GetPozycjaY();
		if (swiat->GetDlugosc() > this->GetPozycjaX() + 1 && swiat->GetMapa()[this->GetPozycjaX() + 1][this->GetPozycjaY()] == NULL)
		{
			pozx += 1;
		}
		else if (0 <= this->GetPozycjaX() - 1 && swiat->GetMapa()[this->GetPozycjaX() - 1][this->GetPozycjaY()] == NULL)
		{
			pozx -= 1;
		}
		else if (swiat->GetSzerokosc() > this->GetPozycjaY() + 1 && swiat->GetMapa()[this->GetPozycjaX()][this->GetPozycjaY() + 1] == NULL)
		{
			pozy +=1;
		}
		else if (0<= this->GetPozycjaY() - 1 && swiat->GetMapa()[this->GetPozycjaX()][this->GetPozycjaY() - 1] == NULL)
		{
			pozy -= 1;
		}
		else
		{
			if (atakujacy)
			{
				wrog.Kolizja(*this, false);
			}
			return;
		}
		this->MakeChild(pozx, pozy);
	}
	else if (wrog.CzyOdbil(*this))
	{
		return;
	}
	else if (atakujacy == false && GetSila() <= wrog.GetSila())
	{
		return;
	}
	else
	{
		int pozycjax = wrog.GetPozycjaX();
		int pozycjay = wrog.GetPozycjaY();
		if (wrog.CzyZwial() && atakujacy)
		{
			this->GetSwiat()->SetMapa(GetPozycjaX(), GetPozycjaY(), NULL);
			this->SetPozycjaX(pozycjax);
			this->SetPozycjaY(pozycjay);
			this->GetSwiat()->SetMapa(GetPozycjaX(), GetPozycjaY(), this);
		}
		else if (CzyZwial() && atakujacy)
		{

		}
		else
		{
			if (atakujacy)
			{
				this->GetSwiat()->GetLog()->Stworz(*this, wrog);
			}
			if (GetSila() > wrog.GetSila())
			{
				
				wrog.Kolizja(*this, false);
				if (!wrog.GetTrujaca())
				{
					if (atakujacy)
					{
						this->GetSwiat()->SetMapa(GetPozycjaX(), GetPozycjaY(), NULL);
						this->SetPozycjaX(wrog.GetPozycjaX());
						this->SetPozycjaY(wrog.GetPozycjaY());
						this->GetSwiat()->SetMapa(wrog.GetPozycjaX(), wrog.GetPozycjaY(), this);
					}
					else
					{
						this->GetSwiat()->SetMapa(wrog.GetPozycjaX(), wrog.GetPozycjaY(), NULL);
					}
				}
				delete &wrog;
			}
			else if (GetSila() == wrog.GetSila())
			{
				if (atakujacy)
				{
					wrog.Kolizja(*this, false);
					if (wrog.GetLiterka() != 'b' && wrog.GetLiterka() != 'j')
					{
						this->GetSwiat()->SetMapa(GetPozycjaX(), GetPozycjaY(), NULL);
						this->SetPozycjaX(wrog.GetPozycjaX());
						this->SetPozycjaY(wrog.GetPozycjaY());
						this->GetSwiat()->SetMapa(wrog.GetPozycjaX(), wrog.GetPozycjaY(), this);
					}
					delete &wrog;
				}
				else
				{
					wrog.Kolizja(*this, false);
				}
			}
			else
			{
				wrog.Kolizja(*this, false);
			}
		}
	}
}
std::pair<int, int> Zwierze::czyAkcja()
{
	std::vector<std::pair<int, int>> tab = swiat->GetSasiadow(this->GetPozycjaX(), this->GetPozycjaY());
	std::pair<int, int> wylosowano;
	for (int i = 0; i < 4; i++)
	{
		int numer = rand() % (4-i);
		wylosowano = tab[numer];
		if (tab[numer].first == -1)
		{
			std::swap(tab[3 - i], tab[numer]);
		}
		else
			break;
	}
	return wylosowano;
}
void Zwierze::Akcja()
{
	std::pair<int, int> pozycje = this->czyAkcja();
	if (pozycje.first == -1)
	{
		return;
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
}
bool Zwierze::CzyOdbil(Organizm &organizm)
{
	return false;
}
bool Zwierze::CzyZwierze()
{
	return true;
}
Zwierze::~Zwierze()
{
}