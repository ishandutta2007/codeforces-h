#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    int n,d;
    scanf("%d %d",&n,&d);
    int a[1005];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=2;
    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]==2*d)
            ans++;
        if(a[i+1]-a[i]>2*d)
            ans+=2;
    }
    printf("%d\n",ans);
}