#include<bits/stdc++.h>
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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
#define MXN 10000
const int mod=998244353;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[1005];
    int ok=1;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>m/2){
            ok=0;
            //printf("-1\n");
        }
    }
    if(!ok){
        printf("-1\n");
    }
    else{
        sort(a,a+n);
        vector<pii> v;
        int ok=1;
        for(int i = n-1;i>=0;i--){
            if(a[i]==0){
                continue;
            }
            else if(a[i]*3<=m){
                v.pb(mp(a[i]*3,a[i]*2));
            }
            else{
                int ook=0;
                for(int j = i-1;j>=0;j--){
                    if(a[j]!=0){
                        if(a[j]+a[i]*2<=m&&a[i]%a[j]==0){
                            ook=1;
                            v.pb(mp(a[i]*2+a[j],a[i]+a[j]));
                            a[j]=0;
                            break;
                        }
                    }
                }
                if(!ook)ok=0;
            }
        }
        if(!ok){
            printf("-1\n");
        }
        else{
            printf("%d\n",v.size());
            for(auto it:v){
                printf("%d %d\n",it.x,it.y);
            }
        }
    //    printf("%d\n",v.size());
    
    }
}
int main(){
   // srand(time(NULL));
    int t=1;0000;
    //scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}