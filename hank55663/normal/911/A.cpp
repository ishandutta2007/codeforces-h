#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
using namespace std;
typedef long long LL;
int main(){
	vector<int> v;
	int Min=1e9+1;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a==Min){
			v.pb(i);
		}
		else if(a<Min){
			Min=a;
			v.clear();
			v.pb(i);
		}
	}
	int ans=1e9;
	for(int i=1;i<v.size();i++){
	//	printf("%d %d\n",v[i],v[i-1]);
		ans=min(ans,v[i]-v[i-1]);
	}
	printf("%d\n",ans);
}