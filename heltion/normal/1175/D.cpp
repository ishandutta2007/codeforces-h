//Author: Heltion
//Date: 2019-06-05
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1000000007;
template<typename T>void no(const T&x){cout<<x;exit(0);}
template<typename T=int>auto read(){T x;cin>>x;return x;}
template<typename T>void maxi(T&x,const T&y){if(y>x)x=y;}
template<typename T>void mini(T&x,const T&y){if(y<x)x=y;}
template<typename T>void sort(vector<T>&v){sort(v.begin(),v.end());}
template<typename T>void subm(T&x,const T&y,const T&m=mod){x-=y;if(x<0)x+=m;}
template<typename T>void addm(T&x,const T&y,const T&m=mod){x+=y;if(x>=m)x-=m;}
template<typename T=int>auto input(int n){vector<T>v(n);for(auto&x:v)cin>>x;return v;}
LL power(LL x,LL r,LL m=mod){LL res=1;for(;r;r>>=1,x=x*x%mod)if(r&1)res=res*x%mod;return res;}
template<typename F,typename R>auto&operator>>(istream&is,pair<F,R>&p){return is>>p.first>>p.second;}
template<typename T>auto&operator<<(ostream&os,const vector<T>&v){for(const auto&x:v)os<<x<<" ";return os;}
template<typename F,typename R>auto&operator<<(ostream&os,const pair<F,R>&p){return os<<p.first<<" "<<p.second;}
constexpr int maxn = 0;

int _main(){
	int n = read(), k = read();
	auto a = input<LL>(n);
	vector<LL> s;
	LL p = 0;
	for(int i = n - 1; i >= 1; i -= 1) s.push_back(p += a[i]);
	sort(s);
	LL ans = p + a[0];
	for(int i = n - 2; i >= n - k; i -= 1) ans += s[i];
	cout << ans;
	return 0;
}

int main(){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);cout<<fixed<<setprecision(12);return _main();}