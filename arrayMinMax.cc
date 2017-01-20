#include <iostream>

using namespace std;

int main(void)
{
	int a[] = {5,14,9,8,10,65,32,1,6,78};
	int tot = sizeof a / sizeof(int);
	int t, i, j, minore = a[0], maggiore = a[tot-1];
	
	for(i = 0; i < tot; i++)
	{
		for(j = 0; j < tot-1; j++)
		{
			if(a[j] > a[j+1]){
				t = a[j+1];
				a[j+1] = a[j];
				a[j] = t;
			}
		}
	}
	
	//for(i = 0; i < tot; i++) cout << a[i] << endl;
	
	/*for(int i = 0; i < tot; i++)
	{
		if(a[i] < minore) minore = a[i];
		else if(a[i] > maggiore) maggiore = a[i];
	}*/
	
	cout << minore << endl;
	cout << maggiore << endl;
	
	return 0;
}
