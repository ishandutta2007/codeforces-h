#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll n,m,ans;
int main(){
	cin>>n>>m;
	rep(i,m) rep(j,m){
		ll a = i*i+j*j;
		if(a%m != 0) continue;
		//mod mi,j
		if(i>n) continue;
		if(j>n) continue;
		ll zan = n-i; zan /= m; if(i==0) zan--;
		ll zan2 = n-j; zan2 /= m; if(j==0) zan2--;
		ans += (zan+1)*(zan2+1);
	}
	cout<<ans<<endl;
}