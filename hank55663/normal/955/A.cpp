#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int hh,mm;
	scanf("%d %d",&hh,&mm);
	mm+=hh*60;
	int h,d,c,n;
	scanf("%d %d %d %d",&h,&d,&c,&n);
	int nexth=max(1200-mm,0)*d+h;
//	printf("%d %d",h,nexth);
	printf("%.12lf\n",min((h+n-1)/n*(double)c,(nexth+n-1)/n*c*0.8));
}
/*
BC
ACC
AABC
CC
ABC
AACC*/