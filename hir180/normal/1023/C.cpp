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

const ll mod = 1000000007;

int n,k;
string str;
vector<P>vec;
bool ex[200005];

int main(){
	cin >> n >> k >> str;
	stack<int>S;
	rep(i,n){
		if(str[i] == '(') S.push(i);
		else{
			int x = S.top(); S.pop();
			vec.pb(mp(x,i));
		}
	}
	rep(i,k/2){
		ex[vec[i].fi] = 1;
		ex[vec[i].sc] = 1;
	}
	rep(i,n) if(ex[i]) printf("%c",str[i]);
	puts("");
}