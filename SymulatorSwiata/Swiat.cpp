#include "stdafx.h"
using namespace std;
Swiat::Swiat(int dlugosc, int szerokosc)
:szerokosc(szerokosc), dlugosc(dlugosc)
{
	mapa = new Organizm**[dlugosc];
	for (int i = 0; i < dlugosc; i++)
	{
		mapa[i] = new Organizm*[szerokosc];
		for (int j = 0; j < szerokosc; j++)
		{
			mapa[i][j] = NULL;
		}
	}
	pocz = NULL;
	log = new Log(szerokosc);
}
std::ostream& operator<<(std::ostream& os, const Swiat& swiat) {
	swiat.Wypisz(os);
	return os;
}
void Swiat::PrzeprowadzTure()
{
	ListaOrganizmow * Obiekt = pocz;
	while (Obiekt != NULL)
	{
		if (Obiekt->organizm != NULL && Obiekt->organizm->GetDataUrodzenia()<this->GetIloscTur())
		{
			if (Obiekt->organizm->GetLiterka() == 'H')
			{
				cout << *this;
			}
					
			Obiekt->organizm->Akcja();
		}
		Obiekt = Obiekt->next;
	}
	OczyscListe();
	iloscTur++;
}
Organizm*** Swiat::GetMapa() const
{
	return mapa;
}
void Swiat::SetMapa(int pozX, int pozY, Organizm* org)
{
	if (pozX >= 0 && pozY >= 0)
	{
		if (org == NULL)
		{
			mapa[pozX][pozY] = NULL;
		}
		else
		{
			mapa[pozX][pozY] = org;
		}
	}
}
ListaOrganizmow* Swiat::GetPocz() const
{
	return pocz;
}
int Swiat::GetDlugosc() const
{
	return dlugosc;
}
int Swiat::GetSzerokosc() const
{
	return szerokosc;
}
void Swiat::Wypisz(std::ostream& out)const
{
	system("CLS");
	out << "Dominik Kwiatkowski 175454";
	out << *log;
	out << ' ';
	for (int i = 0; i < szerokosc; i++)
		out << '#';
	out << endl;
	for (int i = 0; i < dlugosc; i++)
	{
		out << '#';
		for (int j = 0; j < szerokosc; j++)
		{
			if (mapa[i][j] == NULL)
			{
				out << ' ';
			}
			else
			{
				out << *mapa[i][j];
			}
		}
		out << '#';
		out << endl;
	}
	out << ' ';
	for (int i = 0; i < szerokosc; i++)
		out << '#';
}
std::vector<std::pair<int, int>> Swiat::GetSasiadow(int pozx, int pozy)
{
	std::vector<std::pair<int, int>> tab;
	if (pozx>0)
	{
		tab.push_back(pair<int, int>(pozx - 1, pozy));
	}
	else
		tab.push_back(pair<int, int>(-1, -1));
	if (pozx + 1<GetDlugosc())
	{
		tab.push_back(pair<int, int>(pozx + 1, pozy));
	}
	else
		tab.push_back(pair<int, int>(-1, -1));
	if (pozy>0)
	{
		tab.push_back(pair<int, int>(pozx, pozy - 1));
	}
	else
		tab.push_back(pair<int, int>(-1, -1));
	if (pozy+1 <GetDlugosc())
	{
		tab.push_back(pair<int, int>(pozx, pozy + 1));
	}
	else
		tab.push_back(pair<int, int>(-1, -1));
	return tab;
}
void Swiat::Dodaj(Organizm &org)
{
	ListaOrganizmow *pozycja = GetPocz();
	if (pozycja == NULL)
	{
		ListaOrganizmow * pozycja = new ListaOrganizmow;
		pozycja->organizm = NULL;
		pozycja->next = NULL;
		pocz = pozycja;
	}
	pozycja = GetPocz();
	while ((pozycja->next != NULL) && (pozycja->next->organizm == NULL))
	{
		pozycja = pozycja->next;
	}
	if (pozycja->next != NULL)
	{
		while (pozycja->next->organizm->GetInicjatywa() >= org.GetInicjatywa())
		{
			pozycja = pozycja->next;
			while ((pozycja->next != NULL) && (pozycja->next->organizm == NULL))
			{
				pozycja = pozycja->next;
			}
			if (pozycja->next == NULL)
			{
				break;
			}
		}
	}
	ListaOrganizmow * nowy = new ListaOrganizmow;
	nowy->next = pozycja->next;
	nowy->organizm = &org;
	pozycja->next = nowy;
}
void Swiat::Usun(Organizm &org)
{
	ListaOrganizmow *pozycja = GetPocz();
	while ((pozycja->next->organizm==NULL) ||(pozycja->next->organizm->GetPozycjaX() != org.GetPozycjaX()) || (pozycja->next->organizm->GetPozycjaY() != org.GetPozycjaY()) || (pozycja->next->organizm->GetLiterka() != org.GetLiterka()))
	{
		pozycja = pozycja->next;
	}
	pozycja->next->organizm = NULL;
}
void Swiat::OczyscListe()
{
	ListaOrganizmow *pozycja = GetPocz();
	ListaOrganizmow *tmp;
	while (pozycja->next != NULL)
	{
		if (pozycja->next->organizm == NULL)
		{
			tmp = pozycja->next->next;
			delete pozycja->next;
			pozycja->next = tmp;
		}
		pozycja = pozycja->next;
		if (pozycja == NULL)
			break;
	}
}
int Swiat::GetIloscTur() const
{
	return iloscTur;
}
Log *Swiat::GetLog() const
{
	return log;
}
void Swiat::Zapisz() const
{
	fstream plik;
	plik.open("zapis.txt", std::ofstream::out | std::ofstream::trunc);
	if (!plik.good())
	{
		cout << "Blad pliku";
		return;
	}
	plik << GetDlugosc() << endl << GetSzerokosc() << endl;
	ListaOrganizmow* pozycja = GetPocz();
	while (pozycja->next != NULL)
	{
		plik << pozycja->next->organizm->GetLiterka() << endl;
		plik << pozycja->next->organizm->GetDataUrodzenia() << endl;
		plik << pozycja->next->organizm->GetSila() << endl;
		plik << pozycja->next->organizm->GetPozycjaX() << endl;
		plik << pozycja->next->organizm->GetPozycjaY() << endl;
		pozycja = pozycja->next;
	}
	plik.close();
}
void Swiat::Wczytaj()
{
	ListaOrganizmow* pozycja = GetPocz();
	while (pozycja->next != NULL)
	{
		pozycja = pozycja->next;
		delete pozycja->organizm;
	}
	OczyscListe();
	for (int i = 0; i < GetDlugosc(); i++)
	{
		delete mapa[i];
	}
	delete mapa;
	delete log;
	fstream plik;
	plik.open("zapis.txt");
	int wiek, sila, pozycjax, pozycjay;
	char literka;
	plik >> dlugosc >> szerokosc;
	mapa = new Organizm**[dlugosc];
	for (int i = 0; i < dlugosc; i++)
	{
		mapa[i] = new Organizm*[szerokosc];
		for (int j = 0; j < szerokosc; j++)
		{
			mapa[i][j] = NULL;
		}
	}
	pocz = NULL;
	log = new Log(szerokosc);
	while (plik >> literka)
	{
		plik >> wiek >> sila >> pozycjax >> pozycjay;
		WczytajOrganizm(literka, wiek, sila, pozycjax, pozycjay);
	}
}
void Swiat::WczytajOrganizm(char literka, int wiek, int sila, int pozycjax, int pozycjay)
{
	switch (literka)
	{
	case 'w':
		new Wilk(wiek, sila, pozycjax, pozycjay, this);
		break;
	case 'a':
		new Antylopa(wiek, sila, pozycjax, pozycjay, this);
		break;
	case'g':
		new Guarana(wiek, pozycjax, pozycjay, this);
		break;
	case 'l':
		new Lis(wiek, sila, pozycjax, pozycjay, this);
		break;
	case 'b':
		new BarszczSosnowskiego(wiek, pozycjax, pozycjay, this);
		break;
	case 'm':
		new Mlecz(wiek, pozycjax, pozycjay, this);
		break;
	case 'o':
		new Owca(wiek, sila, pozycjax, pozycjay, this);
		break;
	case 't':
		new Trawa(wiek, pozycjax, pozycjay, this);
		break;
	case 'z':
		new Zolw(wiek, sila, pozycjax, pozycjay, this);
		break;
	case 'j':
		new WilczeJagody(wiek, pozycjax, pozycjay, this);
		break;
	case 'H':
		new Czlowiek(wiek, sila, pozycjax, pozycjay, this);
		break;
	default:
		break;
	}
}
