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
#define last Last
#define MXN 200005
void solve(){
    int n;
    scanf("%d",&n);
    char c[55];
    scanf("%s",c);
  //  int x=unique(c,c+n)-c;
//    c[x]=0;
    int vis[26];
    fill(vis,vis+26,0);
  //  printf("%s\n",c);
    for(int i = 0;c[i]!=0;i++){
        if(i!=0&&c[i]!=c[i-1]&&vis[c[i]-'A']){
            printf("No\n");
            return ;
        }
        vis[c[i]-'A']=1;
    }
    printf("YES\n");
}
int main(){
  //  for(int i = 1;i*i<=1e9;i++)s.insert(i*i);
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36
6x+s=ty
x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/