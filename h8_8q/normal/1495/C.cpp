#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define lowbit(x) (x&(-x))
#define mp(x,y) make_pair(x,y)
#define lc (x<<1)
#define rc (x<<1|1)
#define fi first
#define se second
#define mid ((l+r)>>1)
#define fan(x) (((x-1)^1)+1)
#define max Max
#define min Min
#define abs Abs

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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=505;
int t,n,m;
char s[N][N];

signed main()
{
	t=read();
	while(t--)
	{
		memset(s,'\0',sizeof(s));
		n=read();m=read();
		for(int i=1;i<=n;++i)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;i+=3)
		{
			int fl=0;
			for(int j=1;j<=m;++j)
				if(s[i+1][j]=='X'||s[i+2][j]=='X')
				{
					s[i+1][j]='X';
					s[i+2][j]='X';
					fl=1;break;
				}
			if(!fl&&i+2!=n) s[i+1][1]='X',s[i+2][1]='X';
			for(int j=1;j<=m;++j)
				s[i][j]='X';
		}
		if(n%3==0)
		{
			for(int j=1;j<=m;++j)
				if(s[n][j]=='X')
					s[n-1][j]='X';
		}
		for(int i=1;i<=n;++i)
			puts(s[i]+1);
	}
	return 0;
}