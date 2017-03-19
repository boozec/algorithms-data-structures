#include <iostream>

using namespace std;

struct node
{
	int x;
	node* link;
} node;

struct node *crea(int N, struct node *p);

int main()
{
	struct node *lista = NULL;
	
	lista = crea(3, lista);
	
	while(lista != NULL)
	{
		cout << "val -> " << lista->x << endl;
		lista = lista->link;
	}
	return 0;
}

struct node *crea(int N, struct node *p)
{
	struct node *punt;
	p = new struct node;
	
	if(N == 1) {
		cout << "Numero: ";
		cin >> p->x;
		
		punt = p;
		p->link = NULL;
	} else if(N > 1){
		cout << "Numero: ";
		cin >> p->x;
		
		punt = p;
		for(int i = 2; i <= N; i++)
		{
			punt->link = new struct node;
			punt = punt->link;
			cout << "Numero: ";
			cin >> punt->x;
		}
		punt->link = NULL;
	}
	
	return p;
}
