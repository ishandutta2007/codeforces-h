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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL a,k;
        scanf("%lld %lld",&a,&k);
        for(LL i = 1;i<k;i++){
            LL Min=10,Max=0;
            LL tmp=a;
            while(tmp){
                Min=min(Min,tmp%10);
                Max=max(Max,tmp%10);
                tmp/=10;
            }
            if(Min==0)break;
            a+=Min*Max;
        }
        printf("%lld\n",a);
    }
}

/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/