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
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> over;
    int cnt[2005];
    fill(cnt,cnt+m+1,0);
    int a[2005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>m||cnt[a[i]]>=n/m){
            over.pb(i);
        }
        else{
            cnt[a[i]]++;
        }
    }
    int ans=0;
    for(int i = 1;i<=m;i++){
        while(cnt[i]<n/m){
            cnt[i]++;
            a[over.back()]=i;
            over.pop_back();
            ans++;
        }
    }
    printf("%d %d\n",n/m,ans);
    for(int i = 0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */