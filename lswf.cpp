/* INPUT: 
 * 19
 * 
 * OUTPUT:
 * 1000101
 */
#include <iostream>
#include <fstream>
#define MAXG 1000

using namespace std;

int fibonacci(int* fib, int N) 
{
	fib[0] = 1; fib[1] = 1;
	int lst;
	
	for(int i = 2; i < N; i++) {
		fib[i] = fib[i-1] + fib[i-2];
		lst = i;
		if(fib[i] > N) break;
	}
	
	return lst;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int N, i;
	in >> N;
	int caracts[MAXG], somma = 0, potSomma;
	int lastc;
	if(N > 4)
		lastc = fibonacci(caracts, N);
	else {
		caracts[0] = 1; caracts[1] = 1; caracts[2] = 2; caracts[3] = 3;
		if(N == 1) lastc = 1;
		else if(N == 2) lastc = 2;
		else if(N == 3) lastc = 3;
		else lastc = 4;
	}
	int* seq = new int[lastc];
	
<<<<<<< HEAD
	for(i = 0; i < lastc; i++) cout << caracts[i] << ' '; cout << endl;
=======
	for(i = 0; i < lastc; i++) cout << caracts[i] << endl; cout << endl;
>>>>>>> devs
	
	seq[0] = 1;
	for(i = lastc; i > 0; i--) {
		potSomma = somma + caracts[i];
		if(potSomma < N) {
			somma = potSomma;
			seq[i] = 1;
		} else seq[i] = 0;
	}
	for(i = 0; i < lastc; i++) out << seq[i];
	
	delete[] seq;
	in.close();
	out.close();
	return 0;
}
