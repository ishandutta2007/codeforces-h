#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	char c[100005];
	scanf("%s",c);
	char now='a';
	for(int i=0;c[i]!=0;i++){
		while(c[i]<now)c[i]++;
		if(c[i]==now)
		now++;
		if(now=='z'+1)
		break;
	}
	//printf("%c",now);
	if(now=='z'+1)
	printf("%s",c);
	else
	printf("-1\n");
}