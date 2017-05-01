// Hacker Cup 2017
// Round 3
// Pie Packages
// Jacob Plachta

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=getchar();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

#define LIM 2000001
#define MOD 1000000007
#define DIV2 500000004

int Add(int a,int b)
{
	a+=b;
		if (a>=MOD)
			a-=MOD;
	return(a);
}

int Sub(int a,int b)
{
	a-=b;
		if (a<0)
			a+=MOD;
	return(a);
}

int Mult(int a,int b)
{
	return((LL)a*b%MOD);
}

int main()
{
	// vars
	int T,t;
	int N;
	int O,Ao,Bo,Co,Do;
	int C,Ac,Bc,Cc,Dc;
	int i,j,k,d,d2,ans;
	int r1,r2,m;
	LL a,b,c;
	static int E[LIM],dist[LIM],sum[LIM];
	static LL D1[LIM],D2[LIM],S1[LIM],S2[LIM];
	static vector<PR> con[LIM];
	priority_queue<PR> Q;
	// testcase loop
	Read(T);
		Fox1(t,T)
		{
			// input
			Read(N);
				Fox(i,N+1)
					con[i].clear();
			Read(O),Read(Ao),Read(Bo),Read(Co),Read(Do);
				Fox(i,N)
				{
					E[i]=O;
					j=(i+1)%N;
					con[i].pb(mp(j,O));
					con[j].pb(mp(i,O));
					O=((LL)Ao*O+Bo)%Co+Do;
				}
			Read(C),Read(Ac),Read(Bc),Read(Cc),Read(Dc);
				Fox(i,N)
				{
					con[N].pb(mp(i,C));
					con[i].pb(mp(N,C));
					C=((LL)Ac*C+Bc)%Cc+Dc;
				}
			// precompute outer distances/sums
			D1[0]=D2[0]=S1[0]=S2[0]=0;
				Fox(i,N*2)
				{
					D1[i+1]=D1[i]+E[i%N];
					D2[i+1]=D2[i]+E[(N*2-i-1)%N];
					S1[i+1]=Add(S1[i],D1[i+1]%MOD);
					S2[i+1]=Add(S2[i],D2[i+1]%MOD);
				}
			// dijkstra's from center
			Fill(dist,60);
			Q.push(mp(0,N)),dist[N]=0;
				while (!Q.empty())
				{
					d=-Q.top().x;
					i=Q.top().y;
					Q.pop();
						if (d!=dist[i])
							continue;
						Fox(j,Sz(con[i]))
						{
							k=con[i][j].x;
							d2=d+con[i][j].y;
								if (d2<dist[k])
									Q.push(mp(-d2,k)),dist[k]=d2;
						}
				}
			// precompute center distance sums
			sum[0]=0;
				Fox(i,N*2)
					sum[i+1]=Add(sum[i],dist[i%N]);
			// process outer points
			j=ans=0;
				Fox(i,N)
				{
					// advance j to furthest node from i (along outside only)
						for(;;)
						{
							c=D1[j]-D1[i];
							a=min(c,D1[N]-c);
							c=D1[j+1]-D1[i];
							b=min(c,D1[N]-c);
								if (b<=a)
									break;
							j++;
						}
					// binary search for furthest node in i..j which is closer along the ouside
					r1=i,r2=j;
						while (r2>r1)
						{
							m=(r1+r2+1)>>1;
								if (D1[m]-D1[i]<dist[i]+dist[m%N])
									r1=m;
								else
									r2=m-1;
						}
					a=r1;
					// binary search for furthest node in j..(i+N) which is closer along the ouside
					r1=j,r2=i+N;
						while (r2>r1)
						{
							m=(r1+r2)>>1;
								if (D1[i+N]-D1[m]<dist[i]+dist[m%N])
									r2=m;
								else
									r1=m+1;
						}
					b=r1;
						if (a==b)
						{
							c=D1[a]-D1[i];
								if (c<D1[N]-c)
									b++;
								else
									a--;
						}
					// add outer distances i -> i..a
					ans=Add(ans,Sub(S1[a],S1[i]));
					ans=Sub(ans,Mult(D1[i]%MOD,a-i));
					// add outer distances i -> b..(i+N)
					ans=Add(ans,Sub(S2[N*2-b],S2[N*2-(i+N)]));
					ans=Sub(ans,Mult(D2[N*2-(i+N)]%MOD,i+N-b));
					// add distances through center i -> (a+1)..(b-1)
						if (a+1<=b-1)
						{
							ans=Add(ans,Mult(dist[i],b-a-1));
							ans=Add(ans,Sub(sum[b],sum[a+1]));
						}
				}
			// add center distances
			ans=Mult(ans,DIV2);
			ans=Add(ans,sum[N]);
			// output
			printf("Case #%d: %d\n",t,ans);
		}
	return(0);
}