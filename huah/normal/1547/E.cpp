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
using namespace std;
const int N =5e5+5;
int n,k,a[N],b[N],pos[N];
void sol(int cas)
{
  sc(n,k);
  rep(i,1,n) a[i]=b[i]=2000000000;
  rep(i,1,k) sc(pos[i]);
  rep(i,1,k)
  {
    int t;sc(t);
    a[pos[i]]=min(a[pos[i]],t);
    b[pos[i]]=min(b[pos[i]],t);
  }
  for(int i=2;i<=n;i++) b[i]=min(b[i],b[i-1]+1);
  for(int i=n-1;i>=1;i--) a[i]=min(a[i],a[i+1]+1);
  for(int i=1;i<=n;i++) printf(i==n?"%d\n":"%d ",min(a[i],b[i]));
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  srand(time(0));
  int t,cas=0;scanf("%d",&t);
  while(t--)
  {
    sol(++cas);
  }
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/