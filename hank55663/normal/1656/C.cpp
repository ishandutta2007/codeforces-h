#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    int ok=1;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1)ok=0;
    }
    if(ok)printf("yes\n");
    else{
        sort(a,a+n);
        for(int i = 0;i<n-1;i++){
            if(a[i+1]-a[i]==1){
                printf("no\n");
                return;
            }
        }
        printf("yes\n");
    }
}


int main(){
    int t=10000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/