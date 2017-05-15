/* gator 2017
input: 1 5
output: 1
*/

#include <iostream>
#include <fstream>

bool pari(int n) { return ((n % 2) == 0) ? true : false; }

int sequenza(int n, bool pollatz, int tCollatz = -1)
{
	int m, tot = 1;
	
	if(pollatz)
		m = 5;
	else
		m = 3;

	while(n != 1) {		
		if(pari(n))
			n /= 2;
		else
			n = n*m+1;
		
		tot++;
		
		if(tCollatz != -1 && tot > tCollatz)
			break;
	}
	
	return tot;
}

int main()
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	
	int N1, N2, tot = 0, collatz;
	in >> N1 >> N2;
	
	for(int i = N1; i <= N2; i++) {
		collatz = sequenza(i, false);
		if(sequenza(i, true, collatz) < collatz)
			tot++;
	}
	
	out << tot;
	
	out.close();
	in.close();
	
	return 0;
}