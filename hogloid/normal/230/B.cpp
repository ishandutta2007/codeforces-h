#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
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
int table[1000005];
int main(){
	memset(table,1,sizeof(table));
	table[0]=table[1]=0;
	for(int i=2;i*i<1000005;++i) if(table[i]){
		for(int j=i*i;j<1000005;j+=i) table[j]=0;
	}
	int n;cin>>n;
	REP(i,n){
		lint a;cin>>a;
		lint sq=sqrt((double)a)+0.5;
		if(sq*sq==a && table[sq]) puts("YES");
		else puts("NO");
	}


	return 0;
}