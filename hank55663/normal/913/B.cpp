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
//#define size Size
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> v[1005];
	int cnt[1005];
	MEM(cnt);
	for(int i=0;i<n-1;i++){
		int a;
		scanf("%d",&a);
		v[a].pb(i+2);
		cnt[a]++;
	}
	for(int i=1;i<=n;i++){
		int cntt=0;
		if(v[i].empty())
		continue;
		for(auto &it:v[i]){
			if(cnt[it]==0){
				cntt++;
			}
		}
		if(cntt<3){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
	printf("Yes\n");
}