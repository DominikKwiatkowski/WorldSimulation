#include "stdafx.h"
struct ListaOrganizmow
{
	Organizm* organizm;
	ListaOrganizmow* next;
};
class Swiat
{

private:
	Log *log;
	ListaOrganizmow *pocz;
	Organizm***mapa;
	int dlugosc, szerokosc;
	int iloscTur = 0;
	void OczyscListe();
	void WczytajOrganizm(char literka, int wiek, int sila, int pozycjax, int pozycjay);
protected:
	friend std::ostream& operator<<(std::ostream& os, const Swiat& swiat);
	void Wypisz(std::ostream& out) const;
public:
	std::vector<std::pair<int, int>> GetSasiadow(int pozx, int pozy);
	Swiat(int dlugosc, int szerokosc);
	void PrzeprowadzTure();
	Organizm*** GetMapa() const;
	void SetMapa(int pozx, int pozy, Organizm* org);
	void Dodaj(Organizm& org);
	void Usun(Organizm& org);
	ListaOrganizmow* GetPocz() const;
	int GetDlugosc() const;
	int GetSzerokosc() const;
	int GetIloscTur() const;
	Log* GetLog() const;
	void Zapisz() const;
	void Wczytaj();
};