#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2005,mod=998244353;
int n,a[N],b[N];
vector<int> dp[N][N];

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[read()]++;
	for(int i=1;i<=n;++i)
		b[a[i]]++;
	for(int i=n;i>=1;--i)
		b[i]+=b[i+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dp[i][j].resize(n/i+2);
	for(int i=1;i<=b[1];++i)
		for(int j=1;j<=i;++j)
			dp[1][i][j]=1;
	int ans=dp[1][n][1];
	for(int i=2,now=b[1];i<=n;++i)
	{
		int lim=n/i;now+=b[i];
		for(int j=1;j<=now;++j)
		{
			for(int k=min(j-1,lim);k>=1;--k)
				dp[i][j][k]=(dp[i][j][k+1]+dp[i-1][j-k][k])%mod;
		}
		ans=(ans+dp[i][n][1])%mod;
	}
	write(ans);
	return 0;
}