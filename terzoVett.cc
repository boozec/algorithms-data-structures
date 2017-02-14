//	utilizzato compilatore GCC 5.0.4 in ambiente Linux Ubuntu 14.06
	
/*	dati due vettori di grandezza 100, caricarne un terzo esclusivamente
	con i numeri positivi dei due */
	
#include <iostream>
#include <vector>

using namespace std;

const int N = 100;

void inserisci(int*, vector<int>&);

int main()
{
	int vett1[N], vett2[N], i;
	vector<int> vett3;
	
	cout << "Numeri primo vettore: " << endl;
	inserisci(vett1, vett3);
	
	cout << "\nNumeri secondo vettore: " << endl;
	inserisci(vett2, vett3);
	
	cout << "\n\nNumeri positivi nel terzo vettore: ";
	for(i = 0; i < (signed) vett3.size(); i++)
		cout << vett3[i] << " ";

	return 0;
}

void inserisci(int* v, vector<int>& vector)
{
	for(int i = 0; i < N; i++) {
		cout << "Numero: ";
		cin >> v[i];
		
		if(cin.fail()){
			cin.clear();
			break;
		}
		
		if(v[i] > -1) vector.push_back(v[i]);
	}
}
