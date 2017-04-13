/* INPUT: 
 * 11
 * 1 0 2 6 4 5 3 9 8 10 7
 * 
 * OUTPUT:
 * 2
 * 8 2
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

void fCarte(vector<int> c, int N, int s)
{
	int i;
	vector<int>::iterator it;
	vector<int>::iterator start;
	
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
	
	int x;
	vector<int> carteV;
	
	for(i = 0; i < N; i++) {
		in >> x;
		carteV.push_back(x);
	}
	
	for(int i = 0; i < N; i++) {
		fCarte(carteV, N, i);
	}
	
	reverse(carteV.begin(), carteV.end());
	
	for(int i = 0; i < N; i++) {
		fCarte(carteV, N, i);
	}
	
	out << carteOut.size() << endl;
	for(vector<int>::iterator ite = carteOut.begin(); ite != carteOut.end(); ite++) out << *ite << ' ';

	out.close();
	in.close();
	return 0;
}
