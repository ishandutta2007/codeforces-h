#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second
inline int read(){
    int w=0,p=0;char c;
    while(!isdigit(c=getchar()))if(c=='-')p=1;
    while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
    return p?-w:w;
}
const int N=2e5+5;
vector<int>g[N];
int n,q,in[N],id[N],siz[N],cnt;
void dfs(int x){
	siz[x]=1;in[x]=++cnt;id[cnt]=x;
	for(int y:g[x])dfs(y),siz[x]+=siz[y];
}
int main(){
	n=read();q=read();
	REP(i,2,n)g[read()].push_back(i);
	dfs(1);
	while(q--){
		int x=read(),k=read();
		if(siz[x]<k)puts("-1");
		else printf("%d\n",id[in[x]+k-1]);
	}
	return 0;
}