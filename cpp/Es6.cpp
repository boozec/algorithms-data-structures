#include <iostream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int v=5;
	int matrice[v][v];
	for (int i=0;i<v;i++)
	{
		for (int j=0;j<v;j++)
		matrice[i][j]=9999;
	}
	for (int i=1;i<v;i++) matrice[i][i]=0;
	matrice[1][4]=5;
	matrice[1][2]=1;
	matrice[2][3]=2;
	matrice[3][1]=2;
	matrice[3][4]=1;
	matrice[4][1]=3;
	for (int h=1;h<v;h++)
	{
		for (int i=1;i<v;i++)
		{
			for (int j=1;j<v;j++)
			{
				matrice[i][j]=min(matrice[i][j],matrice[i][h]+matrice[h][j]);
			}
		}
	}
	for (int i=1;i<v;i++)
	{
		for (int j=1;j<v;j++)
		cout<<matrice[i][j]<<"  ";
		cout<<endl;
	}
	return 0;
}
