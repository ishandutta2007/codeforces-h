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
int ar[2000005];

int main(){
	cin>>n;
	REP(i,n) ar[i]=i;
	
	int b=0;
	for(int i=2;i<=n;++i){
		for(int j=(n-1)/i*i;j>=0;j-=i){
			ar[min(j+i,n)  + b]=ar[j + b];
		}
		++b;
	}


	REP(i,n) printf("%d\n",ar[i+b]+1);




	return 0;
}