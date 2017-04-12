/* INPUT: 
 * 11
 * 1 0 2 6 4 5 3 9 8 10 7
 * 
 * OUTPUT:
 * 2
 * 8 2
 */
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> carteOut;

void cOutPresente(vector<int>& kr, int x) 
{
	bool s = false;
	for(unsigned i = 0; i < kr.size(); i++)
		if(kr[i] == x) s = true;
		
	if(!s)
		kr.push_back(x);
}

void fCarte(int carte[], int N, int s)
{
	int i;
	vector<int> c;
	vector<int>::iterator it;
	vector<int>::iterator start;
	for(i = 0; i < N; i++) c.push_back(carte[i]);
	
	while(c.size() > 1) {
		//for(it = c.begin(); it != c.end(); it++) cout << *it << ' '; cout << endl;
		int tot = c.size();
		for(i = s; i < tot-1; i++) {
			if(!(((c[i] + c[i+1]) % 2) == 0)) {
				start = c.begin()+i;
				c.erase(start, start+2);
				break;
			}
		}
		
		s = 0;
	}
	cOutPresente(carteOut, c[0]);
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int N, i;
	in >> N;
	
	int* carte = new int[N];
	
	for(i = 0; i < N; i++) in >> carte[i];
	
	for(int i = 0; i < N; i++) {
		fCarte(carte, N, i);
	}
	out << carteOut.size() << endl;
	for(vector<int>::iterator ite = carteOut.begin(); ite != carteOut.end(); ite++) out << *ite << ' ';
	
	delete[] carte;
	out.close();
	in.close();
	return 0;
}
