/* INPUT:
3 4
2
3
1
1 3
1 2
3 2
3 1

OUTPUT:
3
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	
	int numBici, sorpassi, i, x, j, y, m[2];
	in >> numBici;
	in >> sorpassi;
	
	int* posBici = new int[numBici];
	
	// posizioni di base
	for(i = 0; i < numBici; i++)
		in >> posBici[i];
	
	// sorpassi
	for(i = 0; i < sorpassi; i++)
	{
		in >> x;
		in >> y;
		
		for(j = 0; j < numBici; j++)
		{
			if(posBici[j] == x) m[0] = j; //indice valore che sorpassa
			
			if(posBici[j] == y) m[1] = j; //indice valore che viene sorpassato
		}
		
		posBici[m[0]] = y;
		posBici[m[1]] = x;
	}
	
	out << posBici[0];
	
	delete[] posBici;
	
	in.close();
	out.close();
	
	return 0;
}
