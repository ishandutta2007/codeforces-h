#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(int T){
    int n,k,r,c;
    scanf("%d %d %d %d",&n,&k,&r,&c);
    r--;
    c--;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if((i+j)%k==(r+c)%k){
                printf("X");
            }
            else printf(".");
        }
        printf("\n");
    }
  
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/