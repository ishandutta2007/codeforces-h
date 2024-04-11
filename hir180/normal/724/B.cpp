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

int n,m,a[32][32];

int main(){
	cin >> n >> m;
	rep(i,n) rep(j,m){
		cin >> a[i][j];
		a[i][j]--;
	}
	rep(x,m)rep(y,m){
		bool fail = 0;
		rep(i,n){
			int dif = 0;
			rep(j,m){
				if(j == x) dif += a[i][j] != y;
				else if(j == y) dif += a[i][j] != x;
				else dif += a[i][j] != j;
			}
			if(dif > 2) fail = 1;
		}
		if(!fail){ puts("YES"); return 0; }
	}
	puts("NO");
}