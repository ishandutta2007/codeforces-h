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
char s[1000005];
int main(){
	scanf("%s",s);
	n=strlen(s);

	int res=0,delay=0,fem=0;
	REP(i,n){
		if(s[i]=='F'){
			if(fem<i){
				res=i-fem+delay;
				++delay;
			}
			++fem;
		}else{
			if(delay>0) --delay;
		}
	}
	printf("%d\n",res);



	return 0;
}