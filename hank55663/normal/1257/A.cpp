#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x,a,b;
        scanf("%d %d %d %d",&n,&x,&a,&b);
        printf("%d\n",min(n-1,abs(a-b)+x));
    }
}
/*
5 4
8 1 0 3 0
0 0 1 3 8
1
*/