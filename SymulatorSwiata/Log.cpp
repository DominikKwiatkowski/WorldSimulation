#include "stdafx.h"

Log::Log(int dlugosc)
:dlugosc(dlugosc)
{
}
std::ostream& operator<<(std::ostream& os, const Log& Log) {
	Log.Wypisz(os);
	return os;
}
void Log::Wypisz(std::ostream& out)const
{
	out << endl;
	int j = 0;
	int ilosc = 0;
	for (int i = 0; i<3; i++)
	{
		while (ilosc<dlugosc && j < logi.size())
		{
			out << logi[j];
			ilosc += logi[j].size();
			j++;		
		}
		out << endl;
		ilosc = 0;
	}
}
void Log::UsunLogi()
{
	while(logi.size() > 100)
	{
		logi.pop_back();
	}
}
void Log::DodajLog(string log)
{
	logi.push_back(log);
	int j = 0;
	while (j < logi.size()-1)
	{
		swap(logi[j], logi[logi.size() - 1]); 
		j++;
	}
	UsunLogi();
}
string Log::Tlumacz(Organizm&org)
{
	switch (org.GetLiterka())
	{
	case 'w':
		return "wilk";
		break;
	case 'a':
		return "antylopa";
		break;
	case'g':
		return "guarana";
		break;
	case 'l':
		return "lis";
		break;
	case 'b':
		return "barszcz sosnowskiego";
		break;
	case 'm':
		return "mlecz";
		break;
	case 'o':
		return "owca";
		break;
	case 't':
		return "trawa";
		break;
	case 'z':
		return "zolw";
		break;
	case 'j':
		return "wilcza jagoda";
		break;
	case 'H':
		return "czlowiek";
		break;
	default:
		return "dziwadlo";
		break;
	}
}
void Log::Zjedzenie(Organizm &zwyciezca, Organizm&zjedzony)
{
	string zwynaz = Tlumacz(zwyciezca);
	string zjenaz = Tlumacz(zjedzony);
	string tekst1 = " zjadl ";
	string tekst ;
	tekst.append(zwynaz);
	tekst.append(tekst1);
	tekst.append(zjenaz);
	tekst.append(". ");
	DodajLog(tekst);
}
void Log::Stworz(Organizm &org1, Organizm&org2)
{
	if (org1.CzyZwierze() && org2.CzyZwierze())
	{
		if (org1.GetSila() >= org2.GetSila())
		{
			Walka(org1, org2);
		}
		else
		{
			Walka(org2, org1);
		}
	}
	else
	{
		if (org1.CzyZwierze())
		{
			Zjedzenie(org1, org2);
		}
		else
		{
			Zjedzenie(org2, org1);
		}
	}
}
void Log::Walka(Organizm &zwyciezca, Organizm&zjedzony)
{
	string zwynaz = Tlumacz(zwyciezca);
	string zjenaz = Tlumacz(zjedzony);
	string tekst1 = " oraz ";
	string tekst2 = " walczyly ze soba, w konsekwencji ";
	string tekst3 = " zjadl ";
	string tekst;
	tekst.append(zwynaz);
	tekst.append(tekst1);
	tekst.append(zjenaz);
	tekst.append(tekst2);
	tekst.append(zwynaz);
	tekst.append(tekst3);
	tekst.append(zjenaz);
	tekst.append(". ");
	DodajLog(tekst);
}
void Log::Barszczowanie(Organizm &org)
{
	string tekst = Tlumacz(org);
	tekst.append(" zostal zbarszczowany i przepadl na zawsze. ");
	DodajLog(tekst);
}
void Log::Spalenie(Organizm &org)
{
	string tekst = Tlumacz(org);
	tekst.append(" zostal spalony przez Twoja moc. ");
	DodajLog(tekst);
}