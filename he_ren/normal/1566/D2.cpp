#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e2 + 5;
const int MAXM = 3e2 + 5;
const int MAXP = MAXN * MAXM;

pii p[MAXP];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	int pcnt = n * m;
	for(int i=1; i<=pcnt; ++i)
	{
		scanf("%d",&p[i].first);
		p[i].second = i;
	}
	
	sort(p+1,p+pcnt+1);
	int ans = 0;
	for(int l=1; l<=pcnt; l+=m)
	{
		int r = l + m - 1;
		for(int i=l,j=l; i<=r; i=j)
		{
			while(j<=r && p[i].first == p[j].first) ++j;
			reverse(p+i, p+j);
		}
		
		for(int i=l; i<=r; ++i)
			for(int j=i+1; j<=r; ++j)
				if(p[i].second < p[j].second)
					++ans;
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}