/* INPUT:
10
6
2 5
0 2
1 3
5 6
4 7
7 9

OUTPUT:
4*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	
	int giorni, turniTot, i, j, tot = 0, m[2], x;
	
	in >> giorni;
	in >> turniTot;
	
	vector< vector<int> > turni(turniTot, vector<int>(2));
	int* eDay = new int[giorni];
	
	for(i = 0; i < giorni; i++) eDay[i] = 0;
	
	for(i = 0; i < turniTot; i++)
	{
		for(j = 0; j < 2; j++)
		{
			in >> x;
			turni[i][j] = x;
		}
	}
	
	for(i = 0; i < turniTot-1; i++)
	{
		if(turni[i][0] > turni[i+1][0]) {
			m[0] = turni[i][0];
			m[1] = turni[i][1];
			
			turni[i][0] = turni[i+1][0];
			turni[i][1] = turni[i+1][1];
			
			turni[i+1][0] = m[0];
			turni[i+1][1] = m[1];
		}
		
		if(turni[i][1] == giorni-1) {
			m[0] = turni[i][0];
			m[1] = turni[i][1];
			
			turni[i][0] = turni[i+1][0];
			turni[i][1] = turni[i+1][1];
			
			turni[i+1][0] = m[0];
			turni[i+1][1] = m[1];
		}
	}
	
	for(i = 0; i < turniTot-1; i++)
	{
		if(eDay[turni[i][0]] == 0) {
			for(j = turni[i][0]; j <= turni[i][1]; j++) eDay[j] = 1;
			tot++;
		} else if(eDay[turni[i][1]] == 0 && turni[i][1] > turni[i+1][0]) {
			for(j = turni[i][1]; j >= turni[i][0]; j--) eDay[j] = 1;
			tot++;
		}
	}
	
	out << tot << endl;
	
	delete[] eDay;
	in.close();
	out.close();
	
	return 0;
}
