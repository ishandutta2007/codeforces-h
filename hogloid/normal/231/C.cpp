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
int a[100005];
int k,n;
lint sum[100005];
int main(){
	cin>>n>>k;
	REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n,greater<int>());
	REP(i,n) sum[i+1]=sum[i]+a[i];

	int resa=-1,resb;
	REP(i,n){
		int lb=i+1,ub=n+1;
		while(ub-lb>1){
			int md=(lb+ub)>>1;
			if(sum[md]-sum[i]+k>=a[i]*(lint)(md-i)) lb=md;
			else ub=md;
		}
		if(lb-i>=resa){
			resa=lb-i;
			resb=a[i];
		}
	}
	printf("%d %d\n",resa,resb);
		


	return 0;
}