//	utilizzato compilatore GCC 5.0.4 in ambiente Linux Ubuntu 14.06
	
/*	dato un vettore di grandezza 100, stampare i valori caricati 
	precedentemente che sono multipli del numero 2 */
	
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;
	
int n_rand(int&);

const int n = 100;

int main()
{
	srand(time(NULL));
		
	int vett1[n], n_casuale, i;
	vector<int> vett2;
	
	for(i = 0; i < n; i++) {
		n_rand(n_casuale);
		vett1[i] = n_casuale;
	}
	
	cout << "Numeri del vettore: " << endl;
	for(i = 0; i < n; i++) 
		cout << vett1[i] << " ";
	
	cout << "\n\nNumeri del vettore multipli di 2: " << endl;
	for(i = 0; i < n; i++) 
		if((vett1[i] % 2) == 0) 
			vett2.push_back(vett1[i]);
	
	for(i = 0; i < (signed) vett2.size(); i++) 
		cout << vett2[i] << " ";
	
	cout << "\n\n\nPremi INVIO per chiudere il programma";
	cin.get();
	return 0;
}

int n_rand(int& num)
{
	num = rand() % n;
	
	return n;
}
