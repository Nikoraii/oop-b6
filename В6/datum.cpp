#include "datum.h"
bool Datum::jePrestupna() const {
	return godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0;
}

int Datum::brDanaUMesecu() const {
	switch (mesec) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		return jePrestupna() ? 29 : 28;
	}
	return -1;
}

int Datum::brDanaOdPocetkaGodine() const {
	int br_dana = dan;
	for (int i = 1; i < mesec; i++) {
		br_dana += Datum(1, i, godina).brDanaUMesecu();
	}
	return br_dana;
}

Datum Datum::operator++ () { // prefiksni
	dan++;
	return *this;
}
Datum Datum::operator++ (int a) { // postfiksni
	Datum d = *this;
	dan++;
	return d;
}
Datum Datum::operator-- () { // prefiksni
	dan--;
	return *this;
}
Datum Datum::operator-- (int a) { // postfiksni
	Datum d = *this;
	dan--;
	return d;
}
Datum Datum::operator+= (const int& broj) {
	for (int i = 0; i < broj; i++) {
		(*this)++;
	}
	return *this;
}
Datum Datum::operator-= (const int& broj) {
	for (int i = 0; i < broj; i++) {
		(*this)--;
	}
	return *this;
}
Datum Datum::operator+ (const int& broj) {
	Datum d = *this;
	d += broj;
	return d;
}
Datum Datum::operator- (const int& broj) {
	Datum d = *this;
	d -= broj;
	return d;
}
bool Datum::operator== (const Datum& d) const {
	return d.godina == godina && d.mesec == mesec && d.dan == dan;
}

bool Datum::operator< (const Datum& d) const {
	return godina < d.godina
		|| godina == d.godina && mesec < d.mesec
		|| godina == d.godina && mesec == d.mesec && dan < d.dan;
}
bool Datum::operator!= (const Datum& d) const {
	return !(*this == d);
}
bool Datum::operator> (const Datum& d) const {
	return *this != d && !(*this < d);
}
bool Datum::operator<= (const Datum& d) const {
	return *this == d || *this < d;
}
bool Datum::operator>= (const Datum& d) const {
	return *this == d || *this > d;
}

int Datum::brDanaIzmedjuDatuma(const Datum& d) const {
	int brDana = brDanaOdPocetkaGodine();
	for (int i = d.godina; i < godina; i++) {
		brDana += Datum(31, 12, i).brDanaOdPocetkaGodine();
	}
	return brDana;
}
int Datum::brDanaOd1_1_1() const { 
	int brDana = brDanaOdPocetkaGodine();
	for (int i = 1; i < godina; i++) {
		brDana += Datum(31, 12, i).brDanaOdPocetkaGodine();
	}
	return brDana;
}