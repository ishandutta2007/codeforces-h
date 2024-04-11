#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
int a[1000005];
ll rui[1000005];
typedef long double ld;
ld ans[1000005];
priority_queue<pair<ld,ll>>que;

int main(){
	scanf("%d",&n);
	repn(i,n) scanf("%d",&a[i]);
	repn(i,n) rui[i] = rui[i-1]+a[i];
	
	repn(i,n){
		ll sum = a[i];
		ll cnt = 1;
		while(!que.empty() && que.top().fi >= (ld)(sum)/(ld)(cnt)){
			cnt += que.top().sc;
			sum = rui[i] - rui[i-cnt];
			que.pop();
		}
		que.push(mp( (ld)(sum)/(ld)(cnt), cnt));
	}
	
	int cur = n;
	while(!que.empty()){
		ll N = que.top().sc; ld v = que.top().fi; que.pop();
		for(ll i=cur;i>cur-N;i--) ans[i] = v;
		cur -= N;
	}
	assert(cur == 0);
	repn(i,n) printf("%.10Lf\n",ans[i]);
}