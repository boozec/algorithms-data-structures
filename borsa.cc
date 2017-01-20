#include <iostream>

using namespace std;

int main(void)
{
	int a[] = {13,24,7,8,6,15,2,21,17,7,3,19,20,1};
	int minore, diffp, diff = 0, x, y;
	int tot = sizeof a/sizeof(int);
	
	for(int i = 0; i < tot; i++)
	{
		minore = a[i];

		for(int j = i; j < tot-1; j++)
		{
			if(a[j] == minore) continue;
			else if(a[j] > minore) diffp = a[j] - minore;
			if(diffp > diff && diffp > 0) {
				x = i;
				y = j;
				diff = diffp;
			}
		}
	}
	
	cout << "Ti conviene comprare a " << a[x] << " giorno " << x+1 << " e vendere a " << a[y] << " giorno " << y+1 << endl;
	cout << "Il tuo guadagno sarebbe: " << diff;
	
	
	return 0;
}
