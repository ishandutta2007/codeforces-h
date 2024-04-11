#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

ll fac[MAXN], inv[MAXN];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int f1[MAXN], f2[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	f1[0] = f2[0] = 1;
	for(int i=1; i<=n; ++i)
	{
		f1[i] = f1[i-1];
		if(i >= 2) add_mod(f1[i], (ll)f1[i-2] * (i-1) %mod);
		
		f2[i] = 0;
		if(i >= 2) add_mod(f2[i], (ll)f2[i-2] * (i-1) %mod * 2 %mod);
	}
	
	ll ans = 0;
	for(int i=0; i*2<=n; ++i)
		ans = (ans + (ll)C(n-i, i) * f1[n-2*i] %mod * f2[i]) %mod;
	printf("%lld\n",ans);
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}