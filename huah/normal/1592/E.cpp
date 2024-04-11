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
void iary(int *a,int l,int r){rep(i,l,r)sc(a[i]);}
void iary(ll *a,int l,int r){rep(i,l,r)sc(a[i]);}
void oary(int *a,int l,int r){rep(i,l,r)printf(i==r?"%d\n":"%d ",a[i]);}
void oary(ll *a,int l,int r){rep(i,l,r)printf(i==r?"%lld\n":"%lld ",a[i]);}
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e6+5,mod=998244353;
const int bs=19;
int n,a[N],b[N],sum[N],s[N][2],l[N];
int cal(int bit)
{
    rep(i,1,n) sum[i]=sum[i-1]^b[i];
    int ans=0;
    rep(i,1,n)
    if(b[i]>>bit&1)
    {
        int j=i;
        while(j<n&&(b[j+1]>>bit&1)) j++;
        rep(k,i,j)
        {
            if(s[sum[k]][k&1]) ans=max(ans,k-s[sum[k]][k&1]+1);
            if(!s[sum[k-1]][(k&1)^1]) s[sum[k-1]][(k&1)^1]=k;
        }
        rep(k,i,j) s[sum[k-1]][(k&1)^1]=0;
        i=j;
    }
    return ans;
}
void sol(int cas)
{
    sc(n);
    rep(i,1,n) sc(a[i]);
    int ans=0;
    nep(i,bs,0)
    {
        rep(j,1,n) b[j]|=a[j]&(1<<i);
        ans=max(ans,cal(i));
    }
    out(ans);
}
int main()
{
//   freopen("1.in", "r",stdin);
//   freopen("1.out", "w", stdout);
  srand(time(0));
  int t=1,cas=0;
//   scanf("%d",&t);
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