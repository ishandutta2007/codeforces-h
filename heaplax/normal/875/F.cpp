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
#define N 200001
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
int n,m,ans,fa[N];
bool use[N];
struct node
{
	int u,v,val;
	bool operator < (const node& a)const
	{
		return val>a.val;
	}
}p[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	re(n),re(m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
		re(p[i].u),re(p[i].v),re(p[i].val);
	sort(p+1,p+m+1);
	for(int i=1;i<=m;++i)
	{
		int u=find(p[i].u),v=find(p[i].v);
		if(u==v)
		{
			if(!use[u])
				use[u]=1,ans+=p[i].val;
		}
		else if(use[u]+use[v]<=1)
		{
			fa[v]=u;
			use[u]|=use[v];
			ans+=p[i].val;
		}
	}
	printf("%d\n",ans);
}