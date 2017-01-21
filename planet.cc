#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	
	char ch;
	string numero, val[2];
	int oraVuota = -1, giorno[96], i = 0, c = 0;
	
	for(int j = 0; j < 96; j++) giorno[j] = -1;
	
	getline(in, numero);
	int N;
	istringstream(numero) >> N;
	
	int ore[N][2];
	
	while(!in.eof())
	{
		in.get(ch);
		
		if(ch == '\n') {
			val[0] = "";
			val[1] = "";
			i = 0;
			c++;
			
			continue;
		}else if(ch == ' '){
			i++;
		}else {
			val[i] += ch;
			istringstream(val[i]) >> ore[c][i];
		}
		
	}
	
	i = 0;
	while(i < N){
		if(ore[i][0] > ore[i][1]){
			for(int j = ore[i][0]; j < ore[i][1] || j < 96; j++) giorno[j] = 0;
			for(int k = ore[i][1]-1; k >= 0; k--) giorno[k] = 0;
		}else {
			for(int k = ore[i][0]; k < ore[i][1]; k++) giorno[k] = 0;
		}
		i++;
	}
	
	for(i = 0; i < 96; i++) {
		if(giorno[i] == -1) {
			oraVuota = i;
			break;
		}
		
		//cout << i << " " << giorno[i] << endl;
	}
	
	out << oraVuota << endl;
		
	in.close();
	out.close();
	
	return 0;
}
