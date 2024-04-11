#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e6+5,mod=1e9+7;
int n,a[N];
pair<int,int>f[5000005];
int main()
{
  // freopen("1.in","r",stdin);
  // freopen("1.out", "w", stdout);
  sc(n);
  rep(i,1,n)sc(a[i]);
  rep(i,1,n)
    rep(j,i+1,n)
    if(f[a[i]+a[j]]==make_pair(0,0))
      f[a[i]+a[j]]={i,j};
    else
    {
      int t=a[i]+a[j];
      if(i!=f[t].first&&i!=f[t].second&&j!=f[t].first&&j!=f[t].second)
      {
        printf("YES\n");
        printf("%d %d %d %d\n",f[t].first,f[t].second,i,j);
        return 0;
      }
    }
  printf("NO\n");
}