#include <iostream>
#include "datum.h"
using namespace std;

int main() {
	// ODAVDE ZAKOMENTARISATI RADI TESTIRANJA BEZ UNOSA
	int br_datuma = 0;
	cout << "Broj datuma? ";
	cin >> br_datuma;
	Datum* niz = new Datum[br_datuma];
	for (int i = 0; i < br_datuma; i++) {
		cout << "Unesite dan, mesec i godinu za " << i + 1 << ". datum: ";
		cin >> niz[i];
	}
	// DOVDE ZAKOMENTARISATI
	
	// OVAJ DEO OTKOMENTARISATI RADI TESTIRANJA
	/*int br_datuma = 10;
	Datum* niz = new Datum[br_datuma];
	niz[0] = Datum(1, 1, 1988);
	niz[1] = Datum(21, 2, 1998);
	niz[2] = Datum(15, 5, 1965);
	niz[3] = Datum(30, 1, 1974);
	niz[4] = Datum(17, 3, 1958);
	niz[5] = Datum(19, 9, 1988);
	niz[6] = Datum(2, 1, 1992);
	niz[7] = Datum(8, 8, 1964);
	niz[8] = Datum(29, 2, 1992);
	niz[9] = Datum(15, 1, 1973);*/

	for (int i = 0; i < br_datuma; i++) {
		cout << niz[i] << endl;
	}
	int prekid = 0;
	do {
		// ODAVDE ZAKOMENTARISATI RADI TESTIRANJA BEZ UNOSA
		Datum datum_od, datum_do;
		cout << "Unesite datum od: ";
		cin >> datum_od;
		cout << "Unesite datum do: ";
		cin >> datum_do;
		// DOVDE ZAKOMENTARISATI
		
		// OVAJ DEO OTKOMENTARISATI RADI TESTIRANJA
		/*Datum datum_od(1, 1, 1975), datum_do(1,1,1994);*/
		
		int j = 0;
		for (int i = 0; i < br_datuma; i++) {
			if (niz[i] >= datum_od && niz[i] <= datum_do) {
				niz[j++] = niz[i];
			}
		}
		br_datuma = j;
		cout << "-----------" << endl;
		for (int i = 0; i < br_datuma; i++) {
			cout << niz[i] << endl;
		}
		cout << "-----------" << endl;

		if (br_datuma > 1) {
			Datum d1 = niz[0], d2 = niz[1];
			for (int i = 2; i < br_datuma - 1; i++) {
				for (int j = i + 1; j < br_datuma; j++) {
					if (niz[i].brDanaIzmedjuDatuma(niz[j]) < d1.brDanaIzmedjuDatuma(d2)) {
						d1 = niz[i];
						d2 = niz[j];
					}
				}
			}
			cout << "Dva najbliza datuma su: " << d1 << " i " << d2;
		}
		cout << "Prekid (0 - ne, 1 - da)";
		cin >> prekid;
	} while (prekid != 1);
	
}