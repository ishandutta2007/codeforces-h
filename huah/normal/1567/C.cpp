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
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=5e5+5,mod1=1e9+7,mod2=998244353;
#define inf 0x3f3f3f3f
char s[N];
int n;
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        reverse(s+1,s+1+n);
        ll dp[20][2][2];
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for(int i=0;i<n;i++)
          for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++)
            for(int a=0;a<=9;a++)
            for(int b=0;b<=9;b++)
            if((a+b+k)%10==s[i+1]-'0')
            {
              dp[i+1][(a+b+k)>=10][j]+=dp[i][j][k];
            }
        printf("%lld\n",dp[n][0][0]-2);
    }
}