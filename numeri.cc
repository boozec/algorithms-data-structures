#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	fstream file;
	file.open("dati.dat");
	
	int a, b, c, seq = 0, tot = 0, num;
	char stringa[] = "112356812983";
	char l;
	while(true) 
	{
		cin >> a >> b >> c;
		if(a >= 0 && a <= 9 && b >= 0 && b <= 9 && c >= 0 && c <= 9){
			if(a != b && b != c && a != c) break;
		}
	}
	
	file << a << endl;
	file << b << endl;
	file << c << endl;
	file << stringa << endl;
	file.seekg(5, file.beg);
	
	while(!file.eof())
	{
		file.get(l);
		num = l - '0';
		if(seq == 0) {
			if(num == a) seq = 1;
		} else if(seq == 1) {
			if(num == b) seq = 2;
		} else if(seq == 2) {
			if(num == c) seq = 3;
		}
			
		if(seq == 3) { tot++; seq = 0; }	
	}
		
	cout << "\n" << tot;
	file.close();

	return 0;
}
