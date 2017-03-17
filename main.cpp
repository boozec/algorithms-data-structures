#include <iostream>
#define BIANCO 0  //Non Visitato
#define NERO 1   //Visitato
#define GRIGIO //Non Finito
#define INF 999999
#include <vector>
#include <fstream>
#include <queue>
#define MAXN 9999
#define INDEF -1
#include <stack>
using namespace std;
int V=9;  //Nodi
int precedente[MAXN];  //Vettore su cui viene salvato il percorso per arrivare alla destinazione
struct nodo {
	vector <int> adj;
}no[MAXN];;
 
 int bfsVisit (int s)
 {
 		int dist[V];
	int colore[V];
	queue <int> q;
	
	for (int i=0;i<V;i++)
	{
		precedente[i]=-1;
		dist[i]=INF;
		colore[i]=BIANCO;
	}
	dist[s]=INF;
	colore[s]=NERO;
	q.push(s);
	while (!q.empty())
	{
		int a=q.front();
		q.pop();
		for (int i=0;i<no[a].adj.size();i++)
		{
			int b=no[a].adj[i];
			if (colore[b] == BIANCO)
			{
				q.push(b);
				colore[b]=NERO;
				precedente[b]=a;
				dist[b]=dist[a] +1;
			}
		}
	}
	/*
	stack <int> sta;
	int i=3; // arrivo
	sta.push(i);
	while (precedente[i]!=INDEF)
	{
		
	}
	*/ //Procedura iterativa per stampare il percorso fino al nodo sorgente
	
 }
 
 void stampaPercorso (int j)  //Procedura ricorsiva j=precedente[destinazione]
 {
 	if (precedente[j] != INDEF )
 	stampaPercorso(precedente[j]);
 	cout<<j;
 }
int main(int argc, char** argv) {
	
	

	return 0;
}
