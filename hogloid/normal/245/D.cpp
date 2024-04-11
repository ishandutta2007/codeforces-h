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
int n;
int res[105];
int mat[105][105];
int main(){
	cin>>n;
	REP(i,n) REP(j,n) cin>>mat[i][j];
	
	REP(i,105) res[i]=0;

	REP(i,n) REP(j,n) if(i!=j){
		res[i]|=mat[i][j];
		res[j]|=mat[i][j];
	}

	REP(i,n) printf("%d\n",res[i]);
	return 0;
}