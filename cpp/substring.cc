#include <iostream>

using namespace std;

void s(int i, int k, int n, char str[]);

int main()
{
	char ss[] = "SANTO";
	s(0, 4, sizeof(ss), ss);
	
	return 0;
}

void s(int i, int k, int n, char str[])
{
	if(i < n - k){
		if(i < n-k) for(int j = i; j < i+k; j++) cout << str[j];
		cout << "\n";
		s(i+=1, k, n, str);
	}
}
