#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,m;
int able[105][105];
struct uf{
	int par[105];
	uf(){
		memset(par,-1,sizeof(par));
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		par[a]=b;
	}
};
uf u;

int empty[105];
int main(){
	cin>>n>>m;
	int e=0;
	REP(i,n){
		int k;cin>>k;
		if(k==0) empty[i]=1,++e;
		REP(j,k){
			int a;cin>>a;--a;
			able[i][a]=1;
		}
	}

	REP(i,n) REP(j,i) REP(k,m) if(able[i][k] && able[j][k]) u.unite(i,j);

	int g=0;
	REP(i,n) if(u.root(i)==i && !empty[i]) ++g;
	cout<<max(0,g-1)+e<<endl;

	return 0;
}