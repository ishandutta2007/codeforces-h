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
int okA,allA,okB,allB;
int main(){
	int n;cin>>n;
	REP(i,n){
		int t,x,y;cin>>t>>x>>y;
		if(t==1){
			allA+=10;
			okA+=x;
		}else{
			allB+=10;
			okB+=x;
		}
	}
	if(okA*2>=allA) puts("LIVE");
	else puts("DEAD");

	if(okB*2>=allB) puts("LIVE");
	else puts("DEAD");

	return 0;
}