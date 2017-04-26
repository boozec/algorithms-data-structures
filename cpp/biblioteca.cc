#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

int main(void)
{
	ifstream filein;
	ofstream fileout;
	
	filein.open("input.txt");
	fileout.open("output.txt");
	
	time_t rawtime;
	struct tm * timeinfo;
	
	int num[4], i = 0, j = 1, diff, tot[2];
	char ch;
	string cc;
	
	while(!filein.eof())
	{
		filein.get(ch);
		if(ch != ' '){
			cc+=ch;
			istringstream(cc) >> num[i];
		}else {
			i++;
			cc = "";
		}
	}
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	for(i = 0; i < 2; i++){
		timeinfo->tm_year = 2001-1900;
		timeinfo->tm_mon = num[j]-1;
		timeinfo->tm_mday = num[j-1];
	
		mktime(timeinfo);
	
		tot[i] = timeinfo->tm_yday+1;
		j = 3;
	 }
		
	diff = tot[1] - tot[0];
	
	fileout << diff;
	
	filein.close();
	fileout.close();

	return 0;
}
