// ConsoleApplication1.cpp : definisce il punto di ingresso dell'applicazione console.
//
#include "stdafx.h"
#include <iostream>

using namespace std;

static unsigned long int tot = 0;

void hanoi(int d, int inizio, int fine, int transito)
{
	if (d == 1);
	else {
		hanoi(d - 1, inizio, transito, fine);
		hanoi(d - 1, transito, fine, inizio);
	}
	tot++;
}

int main()
{
	int dischi;
	cout << "Numero dischi: ";
	cin >> dischi;

	hanoi(dischi, 1, 3, 2);
	cout << "In totale: " << tot << " mosse" << endl;
	return 0;
}
