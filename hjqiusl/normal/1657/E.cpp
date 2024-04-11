//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 255
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,C[N][N];
int f[N][N];
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void BellaKira()
{
	n=read(),m=read();
	n--;
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	f[0][0]=1;
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<=n;j++)
			for (int k=0;k<=n-j;k++)
			{
				f[i][j+k]=(f[i][j+k]+f[i-1][j]*C[n-j][k]%mod*quickPower(i,k*(k-1)/2+k*(n-j-k))%mod)%mod;
				// cout<<j<<"->"<<j+k<<" "<<f[i-1][j]*C[n-j][k]%mod*quickPower(i,k*(n-j-1))%mod<<endl;
			}
		// cout<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<endl;
	}
	writeln(f[m][n]);
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/