#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

void solve(){   
    LL n,s;
    scanf("%lld %lld",&n,&s);
    LL nn=n;
    while(true){
        LL sum=0;
        LL tmp=n;
        while(tmp){
            sum+=tmp%10;
            tmp/=10;
        }
       // printf("%lld %lld\n",sum,n);
        if(sum<=s){
            printf("%lld\n",n-nn);
            return;
        }
        int cnt=0;
        while(n%10==0){
            n/=10;
            cnt++;
        }
        n/=10;
        cnt++;
        n++;
        while(cnt){
            n*=10;
            cnt--;
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/