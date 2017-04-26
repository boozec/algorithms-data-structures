/*
INPUT:
18
12 6
11 8
15 8
15 20
13 18
12 23
11 40
15 19
11 25
13 36
15 12
12 18
17 11
23 9
28 22
35 26
11 23
15 12

output:
11 96 */
#include <iostream>
#include <fstream>

using namespace std;

struct punteggioGiocatori
{
	int idGiocatore;
	int punteggio;
} player[100];

int ricercaIdGiocatore(int valore, struct punteggioGiocatori* p);

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int N, i, pPlayer, j = 0, rID, nVal, t[2];
	bool s;
	in >> N;
	
	for(i = 0; i < N; i++) {
		player[i].idGiocatore = 0;
		player[i].punteggio = 0;
	}
	
	for(i = 0; i < N; i++) {
		in >> pPlayer;
		rID = ricercaIdGiocatore(pPlayer, player);
		if(rID == -1) {
			player[j].idGiocatore = pPlayer;
			in >> player[j].punteggio;
			j++;
		} else {
			in >> nVal;
			player[rID].punteggio += nVal;
		}
	}
	int last = j;
	do {
		s = false;
		for(int k = 0; k < last; k++)
		{
			if(player[k].punteggio < player[k+1].punteggio) {
				t[0] = player[k].idGiocatore;
				t[1] = player[k].punteggio;
			
				player[k].idGiocatore = player[k+1].idGiocatore;
				player[k].punteggio = player[k+1].punteggio;
			
				player[k+1].idGiocatore = t[0];
				player[k+1].punteggio = t[1];
				
				s = true;
			}
	
		}
		
		last--;
	} while(s);
	
	out << player[0].idGiocatore << " " << player[0].punteggio << endl;
	
	in.close();
	out.close();
}

int ricercaIdGiocatore(int valore, struct punteggioGiocatori* p)
{
	int rID = -1;
	for(int i = 0; i < 100; i++)
	{
		if(p[i].idGiocatore == valore) {
			rID = i;
			break;
		}
	}
	
	return rID;
}
