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
typedef pair<int,int> p;
int V,E;

struct nodo {
	vector <p> adj;
	int dist;
	nodo(){
		dist=INF;
	}
}no[MAXN];
 int colore[MAXN];
 void relax (nodo no[], int u, int z)
 {
 	p v= no[u].adj[z];
 	if (no[v.first].dist> no[u].dist + v.second )
 	 {
 	 	no[v.first].dist= no[u].dist + v.second;
 	 }
 }
 
 void bf (nodo no[],int n, int s)
 {
 	int i,j,z;
 	no[0].dist=0;
 	for (i=0;i<V;i++)  //Scorro 
 	{
 		for (j=0;j<V;j++)
 		{
 			for (z=0;z<no[j].adj.size();z++)
 			{
 				relax(no,j,z); 
 			}
 		}
 	}

 }
 
 
int main(int argc, char** argv) {
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	in>>V>>E;
	int a,b,c;
	for (int i=0;i<E;i++)
	{
		in>>a>>b>>c;
		no[a].adj.push_back(p(b,c));
	}
	bf(no,V,0);  //Adiacenze, numeri di vertici, sorgente
	for (int i=0;i<V;i++)
	{
		cout<<no[i].dist<<endl;
	}
	return 0;
}
