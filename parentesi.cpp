/* INPUT:
[ ( ( [ { { [ ] ] ( ( ( } } ( ) ) ) ) ) ) ] ] ]

output:
11 */
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	
	int i;
	int t = 0, q = 0, g = 0; //tonde, quadre, graffe
	char str[1000], c;
	i = 0;
	while(!in.eof())
	{
		in.get(c);
		if(c == ' ') continue;
		else {
			str[i] = c;
			i++;
		}
	}
	
	int n = strlen(str), tot = 0;
	
	for(int i = 0; i < n; i++)
	{
		if(str[i] == '(') t++;
		else if(str[i] == '[') q++;
		else if(str[i] == '{') g++;
		
		if(str[i] == ')' && t > 0) {
			t--;
			tot++;
		} else if(str[i] == ']' && q > 0) {
			q--;
			tot++;
		} else if(str[i] == '}' && g > 0) {
			g--;
			tot++;
		}
	}
	
	out << tot << endl;
	
	in.close();
	out.close();
	return 0;
}
