#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 1000005
bool isprime(int n){
    for(int i =2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
void solve(){
    int n;
    scanf("%d",&n);
    int val;
     int tot=4*(n-1);
     for(int j = 4;;j++){
                    if(!isprime(j)&&isprime(j+tot)){
                      val=j;
                      break;
                      //  printf("%d ",j);
                    }
                }
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                printf("4 ");
            }
            else{
               printf("%d ",val);
               
            }
        }
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    int n;
    while(t--){
        solve();
    }
}
/*
32 16 15 20 13 2 1
16 8 25 30 10 0 0
5 6 30 24 16 1 1
18 21 39 12 30 1 1
10 8 29 13 36 1 1
24 25 30 31 3 0 0
21 22 10 27 33 0 0
*/