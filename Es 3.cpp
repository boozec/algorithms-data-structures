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
typedef pair <int,int> p;
std::priority_queue<p, std::vector<p>, std::greater<p> > Q;
int V,E;
int matriceAdj[MAXN][MAXN];
int T;
struct nodo {
	vector <int> adj;
	int inizio,fine;
}no[MAXN];
 int colore[MAXN];
 bool Ciclico=false;
 bool dfsVisit (int u)
 {
 	cout<<u<<endl;
 	colore[u]= GRIGIO;
 	int inizio=++T;
 	no[u].inizio=inizio;
 	int a;
 	for (int i=0;i<no[u].adj.size();i++)
 	{
 		a=no[u].adj[i];
 		if (colore[a]==GRIGIO) 
		 {
		 	Ciclico=true;
		 	return 1;
		 }
 		if ( colore[a] == BIANCO )
 		{
 			int b=dfsVisit(a);
 			if (b)
 			{
 				return 1;
 			}
 		}
 	}
 	colore[u]= NERO;
 	int fine=++T;
 	no[u].fine=fine;
 	Q.push(p(fine,inizio));
 	return 0;
 }
 
  void dfsVisit2 (int u)
 {
 	cout<<u<<endl;
 	colore[u]= GRIGIO;
 	int a;
 	for (int i=0;i<no[u].adj.size();i++)
 	{
 		a=no[u].adj[i];
 		if ( colore[a] == BIANCO )
 		dfsVisit(a);
 	}
 	colore[u]= NERO;
 }
 // Le chiamate ricorsive sono quanti sono i nodi GRIGI
 void dfs()
 {
 	for (int i=0;i<V;i++) colore[i]=BIANCO;
 	for (int i=0;i<V;i++) if (colore[i]==BIANCO)  if (dfsVisit(i)) return;
 }
 
 
int main(int argc, char** argv) {
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	in>>V>>E;
	int a,b;
	for (int i=0;i<E;i++)
	{
		in>>a>>b;
		no[a].adj.push_back(b);
	}
	dfs();
	for (int i=0;i<V;i++)
	{
		cout<<"nodo "<<i<<endl;
		cout<<"Inizio "<<no[i].inizio<<"   Fine "<<no[i].fine<<endl;
	}
	if (!Ciclico)
	{
	for (int i=0;i<V;i++) colore[i]=BIANCO;
	b=0;
	while (!Q.empty())
	{
		a=Q.top().first;
		Q.pop();
		if (colore[a]==BIANCO) 
		{
			dfsVisit2(a);
			b++;
		}
	}
	cout<<"Il numero di Componenti connesse e' "<<b;
    }
	return 0;
}
