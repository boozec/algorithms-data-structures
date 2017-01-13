/* programma scritto dagli studenti Cariotti e Crupi
utilizzato compilatore GCC 5.0.4 */

#include <iostream>

using namespace std;

void giorniSettimana(int a);

int main()
{
	float mmAcquaSettimana[7], media;
	int i;
	
	cout << "INSERIRE QUANTI MM DI PIOGGIA SONO CADUTI IN UNA SETTIMANA (0 E' NULLA)\n" << endl;
	
	for(i = 0; i < 7; i++) {
		cout << "Quanti mm di pioggia sono caduti ";
		giorniSettimana(i);
		cout << ": ";
		cin >> mmAcquaSettimana[i];
		media += mmAcquaSettimana[i];
	}
	media/=7;
	cout << "\n";
	cout << "I giorni piovosi sono stati: ";
	for(i = 0; i < 7; i++) {
		if(mmAcquaSettimana[i] > 0.0) {
			giorniSettimana(i);
			cout << " - ";
		}
	}
	
	cout << "\nLa media di pioggia questa settimana e' stata: " << media << endl;
	
	
	return 0;
}

void giorniSettimana(int a)
{
	if(a == 0) cout << "Lunedi'";
	else if(a == 1) cout << "Martedi'";
	else if(a == 2) cout << "Mercoledi'";
	else if(a == 3) cout << "Giovedi'";
	else if(a == 4) cout << "Venerdi'";
	else if(a == 5) cout << "Sabato";
	else cout << "Domenica";
	
}
