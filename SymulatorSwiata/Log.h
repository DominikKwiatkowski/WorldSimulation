#include "stdafx.h"
using namespace std;
class Log
{
private:
	vector<string> logi;
	std::vector<string>::iterator it;
	void UsunLogi();
	int dlugosc;
	void DodajLog(string log);
	string Tlumacz(Organizm &org);
	void Zjedzenie(Organizm& zjadajacy, Organizm& zjedzony);
	void Walka(Organizm& zwyciezca, Organizm& zjedzony);
protected:
	friend std::ostream& operator<<(std::ostream& os, const Log& Log);
	void Wypisz(std::ostream& out) const;
public:
	Log(int dlugosc);
	void Barszczowanie(Organizm& zbarszczowany);
	void Stworz(Organizm& org1, Organizm& org2);
	void Spalenie(Organizm& spalony);
};