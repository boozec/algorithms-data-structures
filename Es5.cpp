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
struct nodo{
	vector<int> adj;
	vector<int> p;
};

int main(int argc, char** argv) {
	int v,e;
	int sorgente;
	nodo no[v];
	
	priority_queue<p> Q;
	int peso[v];
	Q.push(p(0,sorgente));
	
	while(!Q.empty())
	{
		pair <int,int> a=Q.top();
		Q.pop();
		if (a.first > peso[a.second])
		continue;
		
		for (int i=0;i<no[a.second].adj.size();i++)
		{
			if (peso[no[a.second].adj[i]]>a.first+ no[a.second].p[i])
			{
				peso[no[a.second].adj[i]]=a.first + no[a.second].p[i];
				Q.push(p(peso[no[a.second].adj[i]],no[a.second].adj[i]));
			}
		}
		
	}
	return 0;
}
