#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=505;
int n,mod;
ll dp[N];
bool vis[N];
int g[N][N*N];
ll Dp(int n)
{
    if(n==1) return 0;
    if(vis[n]) return dp[n];
    vis[n]=true;
    ll ans=1ll*n*Dp(n-1)%mod;
    int len=(n-1)*(n-2)/2;
    for(int s=1;s<n;s++)
    {
        ll sum=0;
        for(int x=0;x<=len;x++)
        {
            if(x-s-1>=0) sum=(sum+g[n-1][x-s-1])%mod;
            ans=(ans+sum*g[n-1][x]%mod*(n-s)%mod)%mod;
        }
        //x>y+s =>y<=x-s-1
    }
    return dp[n]=ans;
}
int main()
{
    scanf("%d%d",&n,&mod);
    g[1][0]=1;
    for(int i=1;i<n;i++)
    {
        int len=i*(i-1)/2;
        for(int j=0;j<=i*(i-1)/2;j++)
        for(int k=0;k<=i;k++)
        g[i+1][j+k]=(g[i+1][j+k]+g[i][j])%mod;
    }
    printf("%lld\n",Dp(n));
}