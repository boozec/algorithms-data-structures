#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

const int b = 32;

int main()
{
	int v[b] = {0}; //tutti i valori sono uguali a 0
	char str[b];
	int valVuoto, i, j;
	int num = 0;
	
	cin >> str;
	/* se la lunghezza della stringa è inferiore a quella della base, indica da quale punto è vuota */
	if(strlen(str) < b)
		valVuoto = strlen(str);
	
	/* ordina i valori in modo tale da spostarli a blocco, ovvero entrambi gli indici si incrementano
	man mano che ordinano il vettore degli interi. La base - la prima X di 'str' è l'inizio dell'ordine
	del vettore degli int.
	
	Seguendo questa logica e questo esempio:
	STR -
	1 0 x x x x x x
	
	V -
	x x x x x x 1 0
	*/
	for(i = b - valVuoto, j = 0; i < b; i++, j++)
		v[i] = str[j] - '0';
	
	//il vettore viene letto in ordine decrescente, mentre le potenze in crescente
	for(i = b - 1, j = 0; i > -1; i--, j++)
		num += v[i] * pow(2, j);
		
	cout << num << endl;
		
	return 0;
}
