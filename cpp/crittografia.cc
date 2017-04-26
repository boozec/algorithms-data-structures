#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

void converti(char *str, int size);
void vocalic(char *str, int size);

char consonantiMin[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
char consonantiMax[] = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Z'};

int main()
{
	ifstream in;
	ofstream out;
	
	in.open("input.txt");
	out.open("output.txt");
	
	int N;
	string ca;
	
	getline(in, ca);
	istringstream(ca) >> N;
	
	for(int i = 0; i < N; i++){
		getline(in, ca);
		char *c = new char[ca.length() + 1];
		strcpy(c, ca.c_str());
		converti(c, ca.length() + 1);
		out << c << endl;
		delete[] c;
	}
	
	in.close();
	out.close();
	
	return 0;
}

void vocalic(char *str, int i)
{
	if(str[i] == 'a') str[i] = 'e';
	else if(str[i] == 'e') str[i] = 'i';
	else if(str[i] == 'i') str[i] = 'o';
	else if(str[i] == 'o') str[i] = 'u';
	else if(str[i] == 'u') str[i] = 'y';
	else if(str[i] == 'y') str[i] = 'a';
	else if(str[i] == 'A') str[i] = 'E';
	else if(str[i] == 'E') str[i] = 'I';
	else if(str[i] == 'I') str[i] = 'O';
	else if(str[i] == 'O') str[i] = 'U';
	else if(str[i] == 'U') str[i] = 'Y';
	else if(str[i] == 'Y') str[i] = 'A';
	else if(str[i] == 'z') str[i] = 'b';
	else if(str[i] == 'Z') str[i] = 'B';
	else if(str[i] == '0') str[i] = '1';
	else if(str[i] == '1') str[i] = '2';
	else if(str[i] == '2') str[i] = '3';
	else if(str[i] == '3') str[i] = '4';
	else if(str[i] == '4') str[i] = '5';
	else if(str[i] == '5') str[i] = '6';
	else if(str[i] == '6') str[i] = '7';
	else if(str[i] == '7') str[i] = '8';
	else if(str[i] == '8') str[i] = '9';
	else if(str[i] == '9') str[i] = '0';
}

void converti(char *str, int size)
{
	bool cpres = false;
	for(int i = 0; i < size-1; i++){
		int s=1;
		vocalic(str,i);
		for(unsigned int j = 0; j < sizeof consonantiMin; j++){
			if(str[i] == consonantiMin[j] || str[i] == consonantiMax[j]){
				cpres = true;
				if(str[i]+1 == 'A' || str[i]+1 == 'E' || str[i]+1 == 'I' || str[i]+1 == 'O' || str[i]+1 == 'U' || str[i]+1 == 'Y' ||
					str[i]+1 == 'a' || str[i]+1 == 'e' || str[i]+1 == 'i' || str[i]+1 == 'o' || str[i]+1 == 'u' || str[i]+1 == 'y') s = 2;
				else s = 1;
			}
		}
		if(cpres == true) str[i]+=s;
		cpres = false;
	}
}
