#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
mt19937_64 gen(time(0));
ll rdint(ll l,ll r){return uniform_int_distribution<ll>(l,r)(gen);}
const int N=5e5+5,mod=1e9+7;
#define inf 0x3f3f3f3f
int n,ss;
ll a[N];
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t=1;
    sc(t);
    while(t--)
    {
      sc(n,ss);
      rep(i,1,n) sc(a[i]);
      rep(i,1,n) a[i]+=a[i-1];
      int top=0,s[N];
      s[++top]=n+1;
      a[n+1]=-1e18;
      int x,y,len=0;
      nep(i,n,0)
      {
        while(a[s[top]]>=a[i]) top--;
        s[++top]=i;
        if(i<n)
        {
          int l=1,r=top;
          while(l<r)
          {
            int m=(l+r+1)>>1;
            if(a[i]-a[s[m]]>ss) l=m;
            else r=m-1;
          }
          if(s[l]-1-i>len)
            len=s[l]-1-i,x=i+1,y=s[l]-1;
        }
      }
      if(len==0) out(-1);
      else out(x,y);
    }
}