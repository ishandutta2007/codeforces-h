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
#define MXN 10005
#define less Less
int main(){
    LL r;
    scanf("%lld",&r);
    if(r<5){
        printf("NO\n");
    }
    else if(r%2==1){
        printf("%lld %lld\n",1ll,(r-3)/2);
    }
    else{
        printf("NO\n");
    }
}