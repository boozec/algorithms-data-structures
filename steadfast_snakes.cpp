// Hacker Cup 2017
// Round 3
// Steadfast Snakes
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

#define LIM 800008

int L[2];
LL BLT[2][2][LIM];

void Update(int a,int b,int i,int v)
{
	for(i++;i<=L[a];i+=(i&-i))
		BLT[a][b][i]+=v;
}

LL Query(int a,int b,int i)
{
	LL v=0;
		for(i++;i>0;i-=(i&-i))
			v+=BLT[a][b][i];
	return(v);
}

int main()
{
	// vars
	int T,t;
	int N,A,B,C;
	LL K;
	int i,j,c,v,ans;
	int r1,r2,m;
	LL s;
	static int H[LIM];
	static int n1,n2,c1[LIM],c2[LIM],v1[LIM],v2[LIM],vc1[LIM],vc2[LIM];
	// testcase loop
	Read(T);
		Fox1(t,T)
		{
			// input
			scanf("%d%lld",&N,&K);
			Read(v),Read(A),Read(B),Read(C);
				Fox(i,N)
				{
					H[i]=v;
					v=((LL)A*v+B)%C+1;
				}
			// check if there's a single dominating ladder
			j=0;
				Fox(i,N)
					if (H[i]>H[j])
						j=i;
				Fox(i,N)
					if ((i!=j) && (H[i]>H[j]-K-abs(i-j)))
						break;
				if (i==N)
				{
					// special case - only shorten the dominating ladder
					ans=0;
						Fox(i,N)
							if (i!=j)
								Max(ans,H[j]-(int)K+H[i]+abs(i-j));
					goto Done;
				}
			// compress diagonal coordinates
			n1=n2=0;
				Fox(i,N)
				{
					c1[n1++]=v1[i]=i-H[i];
					c2[n2++]=v2[i]=-i-H[i];
				}
			sort(c1,c1+n1);
			sort(c2,c2+n2);
			L[0]=n1=unique(c1,c1+n1)-c1;
			L[1]=n2=unique(c2,c2+n2)-c2;
				Fox(i,N)
				{
					vc1[i]=lower_bound(c1,c1+n1,v1[i])-c1;
					vc2[i]=lower_bound(c2,c2+n2,v2[i])-c2;
				}
			// init BLTs
			Fill(BLT,0);
				Fox(i,N)
				{
					Update(1,0,vc2[i],1);
					Update(1,1,vc2[i],v2[i]);
				}
			// try every possible pyramid center x-coordinate
			ans=2*INF+N;
				Fox(i,N)
				{
					// move ladder i from right to left BLT
					Update(0,0,vc1[i],1);
					Update(0,1,vc1[i],v1[i]);
					Update(1,0,vc2[i],-1);
					Update(1,1,vc2[i],-v2[i]);
					// centered on i
					r1=max(i+1,N-i),r2=INF+N;
						while (r2>=r1)
						{
							m=(r1+r2)>>1;
							// left
							v=i-m;
							c=lower_bound(c1,c1+n1,v)-c1-1;
							s=Query(0,0,c)*v-Query(0,1,c);
							// right
							v=-i-m;
							c=lower_bound(c2,c2+n2,v)-c2-1;
							s+=Query(1,0,c)*v-Query(1,1,c);
								if (s<=K)
									r2=m-1,Min(ans,2*m);
								else
									r1=m+1;
						}
					// centered on i+0.5
						if (i==N-1)
							break;
					r1=max(i+1,N-i-1),r2=INF+N;
						while (r2>=r1)
						{
							m=(r1+r2)>>1;
							// left
							v=i-m;
							c=lower_bound(c1,c1+n1,v)-c1-1;
							s=Query(0,0,c)*v-Query(0,1,c);
							// right
							v=-(i+1)-m;
							c=lower_bound(c2,c2+n2,v)-c2-1;
							s+=Query(1,0,c)*v-Query(1,1,c);
								if (s<=K)
									r2=m-1,Min(ans,2*m+1);
								else
									r1=m+1;
						}
				}
Done:;
			printf("Case #%d: %d\n",t,ans);
		}
	return(0);
}
