#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n; ll a[300005],b[300005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	b[0] = 1LL; for(int i=1;i<300005;i++) b[i] = b[i-1]*2LL%mod;
	ll res = 0;
	for(int i=0;i<n;i++){
		ll co = (b[i]-1)-(b[n-1-i]-1);
		co = (co%mod+mod)%mod;
		res += co*a[i]%mod;
	}
	cout << res%mod << endl;
}