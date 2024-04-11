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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
vector<ll>pos[65];;


int main(){
	cin >> n;
	repn(i,n){
		ll a; scanf("%lld",&a);
		ll b = a;
		rep(j,65){
			if(a%2 != 0){
				pos[j].pb(b); break;
			}
			a/=2;
		}
	}
	P mx = P(0,0);
	rep(i,65) if(mx.fi < pos[i].size()) mx = mp(pos[i].size(),i);
	printf("%d\n",n-mx.fi);
	rep(i,65){
		if(i == mx.sc) continue;
		rep(j,pos[i].size()) printf("%lld\n",pos[i][j]);
	}
}