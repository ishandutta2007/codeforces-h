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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[100005];
    scanf("%s",c);
    int ans=0;
    vector<int> v;
    for(int i=0;c[i]!=0;i++){
        ans+=c[i]-'0';
        ans+=(c[i]-'0')*10;
        if(c[i]=='1')v.pb(i);
    }
    if(v.size()){
        int dis=n-1-v.back();
        if(dis<=k){
            k-=dis;
            v.pop_back();
            ans-=10;
        }
    } 
    if(v.size()){
        int dis=v[0];
        if(dis<=k){
            k-=dis;
            v.pop_back();
            ans-=1;
        }
    }
    printf("%d\n",ans);
}

int main(){
    srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}