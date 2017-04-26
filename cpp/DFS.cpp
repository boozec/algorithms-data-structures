#include <iostream>
#define BIANCO 0  //Non Visitato
#define NERO 2   //Visitato
#define GRIGIO 1 //Non Finito
#define INF 999999
#include <vector>
#include <fstream>
#include <queue>
#define MAXN 9999
#define INDEF -1
#include <stack>
using namespace std;
int V=9;
int matriceAdj[MAXN][MAXN];
 int colore[MAXN];
 //DFS Tramite matrice di adiacenza
 void dfsVisit (int u)
 {
 	colore[u]= GRIGIO;
 	for (int i=0;i<V;i++)
 	{
 		if (matriceAdj[u][i] == 1 && colore[i] == BIANCO )
 		dfsVisit(i);
 	}
 	colore[u]= NERO;
 }
 // Le chiamate ricorsive sono quanti sono i nodi GRIGI
 int dfs()
 {
 	for (int i=0;i<V;i++) colore[i]=BIANCO;
 	for (int i=0;i<V;i++) if (colore[i]==BIANCO) dfsVisit(i);
 }
 
int main(int argc, char** argv) {
	
	//Vanno settati i dati riguardanti gli archi esistenti

	return 0;
}
