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
#define pdd pair<double,double>
#define cpdd const pdd
int main(){
    printf("?");
    for(int i = 1;i<=100;i++){
        printf(" %d",i);
    }
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    printf("?");
    for(int i = 1;i<=100;i++){
        printf(" %d",i*128);
    }
    printf("\n");
    fflush(stdout);
    int y;
    scanf("%d",&y);
    int a=127<<7,b=127;
    int ans=(a&x)+(b&y);
    printf("! %d\n",ans);
    fflush(stdout);
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
24
 */