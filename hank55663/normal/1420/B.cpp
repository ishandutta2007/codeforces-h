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
    int n;
    scanf("%d",&n);
    LL cnt[55];
    MEM(cnt);
    for(int i = 0;i<n;i++){
        int a;
        scanf("%d",&a);
        for(int j = 30;j>=0;j--){
            if(a&(1<<j)){
                cnt[j]++;
                break;
            }
        }
    }
    LL ans=0;
    for(int i = 30;i>=0;i--){
        ans+=cnt[i]*(cnt[i]-1)/2;
    }
    printf("%lld\n",ans);
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