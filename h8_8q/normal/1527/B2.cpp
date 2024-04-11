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
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

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

const int N=1e3+5;
int t,n;
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s+1);
		int flag=1,sum=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]!=s[n-i+1])
				flag=0;
			if(s[i]=='0') sum++;
		}
		if(!flag)
		{
			if(n%2==1&&s[n/2+1]=='0'&&sum==2)
				printf("DRAW\n");
			else printf("ALICE\n");
		}
		else
		{
			if(n%2==1&&s[n/2+1]=='0')
			{
				sum--;
				if(sum==0)
					printf("BOB\n");
				else printf("ALICE\n");
			}
			else
			{
				if(sum==0)
					printf("DRAW\n");
				else printf("BOB\n");
			}	
		}
		
	}
	return 0;
}