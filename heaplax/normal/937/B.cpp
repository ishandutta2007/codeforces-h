#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int a,b;
bool prime(int x)
{
	for(int i=2;i*i<=x && i<=a;++i)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	re(a),re(b);
	for(b;a<b;--b)
		if(prime(b))
		{
			printf("%d\n",b);
			return 0;
		}
	puts("-1");
}