#ifndef __datum_h__
#define __datum_h__
#include <iostream>
using namespace std;

class Datum {
	int dan, mesec, godina;
	short prikaz;
public:
	Datum(): dan(0), mesec(0), godina(0) {}
	Datum(const int& d, const int& m, const int& g) : dan(d), mesec(m), godina(g) {}
	friend int getDan(const Datum& d) { return d.dan; }
	friend int getMesec(const Datum& d) { return d.mesec; }
	friend int getGodina(const Datum& d) { return d.godina; }
	bool jePrestupna() const;
	int brDanaUMesecu() const;
	int brDanaOdPocetkaGodine() const;
	Datum operator++ (); // prefiksni
	Datum operator++ (int); // postfiksni
	Datum operator-- (); // prefiksni
	Datum operator-- (int); // postfiksni
	Datum operator+ (const int&);
	Datum operator- (const int&);
	Datum operator+= (const int&);
	Datum operator-= (const int&);
	bool operator == (const Datum& d) const;
	bool operator != (const Datum& d) const;
	bool operator < (const Datum& d) const;
	bool operator > (const Datum& d) const;
	bool operator <= (const Datum& d) const;
	bool operator >= (const Datum& d) const;
	friend ostream& operator<< (ostream& out, const Datum& d) {
		return out << d.dan << "." << d.mesec << "." << d.godina << ".";
	}
	friend istream& operator>> (istream& in, Datum& d) {
		return in >> d.dan >> d.mesec >> d.godina;
	}
	int brDanaIzmedjuDatuma(const Datum& d) const;
	int brDanaOd1_1_1() const;

	int operator- (const Datum& d) const { return brDanaIzmedjuDatuma(d); }
};

#endif