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
#define MXN 1500
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int c,m,x;
        scanf("%d %d %d",&c,&m,&x);
        int tot=c+m+x;
        printf("%d\n",min(c,min(m,tot/3)));
    }
    return 0;
}
/*
5 5
 _ _ _ _ _
|_ _  |_  |
|  _| |  _|
| |_   _| |
|    _ _  |
|_|_ _ _|_|

*/