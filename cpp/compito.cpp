#include <iostream>
#define N 5

using namespace std;

struct puntiVendita {
	string citta;
	float entrate;
	float uscite;
};

struct puntiVendita pV[N];
bool utili(struct puntiVendita p);
void carica();
void ord();
void visualizza();

int main()
{
	carica();
	
	for(int i = 0; i < N; i++) {
		if(!utili(pV[i]))
			cout << "Attenzione" << endl;
	}
	
	ord();
	visualizza();
	
	return 0;
}

bool utili(struct puntiVendita p)
{
	return ((p.uscite > p.entrate) ? false : true);
}

void carica()
{
	pV[0].citta = "Catania";
	pV[0].entrate = 380;
	pV[0].uscite = 245;
	pV[1].citta = "Ragusa";
	pV[1].entrate = 231;
	pV[1].uscite = 175;
	pV[2].citta = "Siracusa";
	pV[2].entrate = 214;
	pV[2].uscite = 227;
	pV[3].citta = "Messina";
	pV[3].entrate = 294;
	pV[3].uscite = 189;
	pV[4].citta = "Enna";
	pV[4].entrate = 145;
	pV[4].uscite = 175;
}

void ord()
{
	struct puntiVendita t;
	bool s;
	int last = N-1;
	
	do {
		s = false;
		
		for(int i = 0; i < last; i++) {
			if(pV[i].entrate > pV[i+1].entrate) {
				t.citta = pV[i].citta;
				t.entrate = pV[i].entrate;
				t.uscite = pV[i].uscite;
				
				pV[i].citta = pV[i+1].citta;
				pV[i].entrate = pV[i+1].entrate;
				pV[i].uscite = pV[i+1].uscite;
				
				
				pV[i+1].citta = t.citta;
				pV[i+1].entrate = t.entrate;
				pV[i+1].uscite = t.uscite;
				
				s = true;
			}
		}
		
		last--;
	} while(s);
}

void visualizza()
{
	for(auto i : pV) {
		cout << i.entrate << endl;
	}
}
		
		
		
		
		
		
	
