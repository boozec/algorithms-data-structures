// Hacker Cup 2017
// Round 3
// Sluggish Security
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

#define LIM 2000005
#define MOD 1000000007

int A[LIM],B[LIM],S[LIM];
LL fct[LIM],ifct[LIM];

PR gcd(int a,int b)
{
		if (!b)
			return(mp(1,0));
	PR p=gcd(b,a%b);
	return(mp(p.y,p.x-p.y*(a/b)));
}

int Ch(int n,int k)
{
	return(fct[n]*ifct[k]%MOD*ifct[n-k]%MOD);
}

int main()
{
	// vars
	int T,t;
	int N,Ka,Kb;
	int i,j,a,b;
	int ans;
	// precompute factorials and their modular inverses
		Fox(i,LIM)
		{
			fct[i]=i ? fct[i-1]*i%MOD : 1;
			ifct[i]=gcd(fct[i],MOD).x;
				if (ifct[i]<0)
					ifct[i]+=MOD;
		}
	// testcase loop
	Read(T);
		Fox1(t,T)
		{
			// input
			Read(N);
			Read(A[0]),Read(Ka),N=1;
				while (Ka--)
				{
					Read(a),Read(b);
						Fox(i,b)
							Read(S[i]);
						while (a--)
							Fox(i,b) {
								A[N]=A[N-1]+S[i];
								N++;
							}
				}
			Read(B[0]),Read(Kb),N=1;
				while (Kb--)
				{
					Read(a),Read(b);
						Fox(i,b)
							Read(S[i]);
						while (a--)
							Fox(i,b) {
								B[N]=B[N-1]+S[i];
								N++;
							}
				}
			// pad arrays
			a=-1;
				Fox(j,4)
				{
					A[N+j]=a--;
					B[N+j]=a--;
				}
			// iterate through
			ans=1;
			i=j=a=b=0;
				while ((i<N) || (j<N))
					if (
						(A[i]==B[j]) ||
						(A[i]==B[j+1]) && (A[i+1]==B[j]) ||
						(A[i]==A[i+2]) && (A[i+1]==B[j]) ||
						(B[j]==B[j+2]) && (B[j+1]==A[i])
					) {
						// cross pattern, must end current streaks
						ans=(LL)ans*Ch(a+b,a)%MOD;
						a=b=0;
							if (A[i]==B[j])
								i++,j++;
							else
							{
								ans=(ans<<1)%MOD;
									if (A[i]==A[i+2])
										i+=3,j++;
									else
									if (B[j]==B[j+2])
										j+=3,i++;
									else
										i+=2,j+=2;
							}
					}
					else
					// continue one of the current streaks?
					if (A[i]==A[i+1])
						i+=2,a++;
					else
					if (B[j]==B[j+1])
						j+=2,b++;
					else
					if ((A[i]==A[i+2]) && (A[i+1]==A[i+3]))
						i+=4,a++;
					else
					if ((B[j]==B[j+2]) && (B[j+1]==B[j+3]))
						j+=4,b++;
					else
					{
						// impossible pattern
						ans=0;
						break;
					}
			ans=(LL)ans*Ch(a+b,a)%MOD;
			// output
			printf("Case #%d: %d\n",t,ans);
		}
	return(0);
}