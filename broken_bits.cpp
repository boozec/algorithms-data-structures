// Hacker Cup 2017
// Round 3
// Broken Bits
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

int main()
{
	// vars
	int T,t;
	int N,K;
	int i,a,b,ones,origOnes,forceZero;
	bool allOnes;
	LL v1,v2,ans;
	int origL[60],L[60];
	// testcase loop
	Read(T);
		Fox1(t,T)
		{
			// input
			Read(N),Read(K);
			ones=0;
				Fox(i,N)
					Read(L[i]),ones+=L[i];
			origOnes=ones=K-ones;
			memcpy(origL,L,sizeof(L));
			// all unknowns must be 0 or 1?
				if ((!ones) || (N==K))
				{
					ans=0;
					goto Done;
				}
			// 2 leading 0s (can never differentiate them)?
				if (L[0]+L[1]==0)
				{
					ans=-1;
					goto Done;
				}
			// try all possible key 0 sequences
			ans=0;
				Fox1(a,N-1)
					if ((!origL[a]) && (origL[a-1]))
						Fox(forceZero,2)
						{
							// find end of key 0 sequence
							memcpy(L,origL,sizeof(L));
							ones=origOnes;
								FoxI(i,a,N-1)
									if (L[i])
										break;
							b=i-1;
							// allocate as many 1s on the left of the key sequence as possible
							// (but leaving at least 1, and optionally forcing one of them to be 0)
							allOnes=1;
								Fox(i,a)
									if (!L[i])
										if ((ones>1) && ((!allOnes) || (!forceZero)))
											L[i]=1,ones--;
										else
											allOnes=0;
							// allocate as many 1s as close to the end as possible (but leaving at least 1)
								FoxRI(i,b+1,N-1)
									if ((!L[i]) && (ones>1))
										L[i]=1,ones--;
							// in key sequence, use smallest possible allocation
								if (!ones)
									continue;
								FoxRI(i,a,b)
									if (ones)
										L[i]=1,ones--;
								if (ones)
									continue;
							// if left of key sequence is all 1s, use 2nd-smallest allocation instead
								if (allOnes)
									if (!next_permutation(L+a,L+b+1))
										continue;
							v1=0;
								Fox(i,N)
									v1=v1*2+L[i];
							// state will be known once key sequence wraps around
								FoxI(i,a,N-1)
									L[i]=1;
							v2=0;
								Fox(i,N)
									v2=v2*2+L[i];
							Max(ans,v2-v1+1);
						}
			// output
Done:;
			printf("Case #%d: %lld\n",t,ans);
		}
	return(0);
}