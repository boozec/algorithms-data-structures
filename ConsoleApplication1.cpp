// ConsoleApplication1.cpp : definisce il punto di ingresso dell'applicazione console.
//
#include "stdafx.h"
#include <iostream>

using namespace std;

bool palindromo(int i, int j, char str[])
{
	if (i >= j) return true;
	else if (str[i] == str[j]) return palindromo(i + 1, j - 1, str);
	else return false;
}

int main()
{
	char parola[] = "onorarono";

	cout << ( (palindromo(0, sizeof parola - 2, parola) == 1) ? "E' palindromo" : "Non e' palindromo" ) << endl;

	cin.get();

    return 0;
}

