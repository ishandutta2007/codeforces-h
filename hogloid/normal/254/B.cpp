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
int use[100005];
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	REP(i,n){
		int m,d,p,t;cin>>m>>d>>p>>t;
		--m;

		int date=500;
		REP(j,m) date+=month[j];
		date+=d-1;

		REP(j,t) use[date-1-j]+=p;
	}
	int res=0;
	REP(i,100005) res=max(res,use[i]);
	cout<<res<<endl;






	return 0;
}