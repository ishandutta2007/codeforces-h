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
void solve(int T){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[55];
    int ok=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i])ok=1;
    }
    if(ok)printf("YES\n");
    else printf("NO\n");

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