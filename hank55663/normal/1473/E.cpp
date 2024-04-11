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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 100000
#define rank Rank
vector<pii> v[1000005];
LL dis[1000005];
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i  =0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        for(int t=0;t<2;t++){
        v[x].pb(mp(y,w));
        v[x].pb(mp(y+n,0));
        v[x].pb(mp(y+2*n,2*w));
        v[x].pb(mp(y+3*n,w));
        v[x+n].pb(mp(y+3*n,2*w));
        v[x+n].pb(mp(y+n,w));
        v[x+2*n].pb(mp(y+3*n,0));
        v[x+2*n].pb(mp(y+2*n,w));
        v[x+3*n].pb(mp(y+3*n,w));
            swap(x,y);
        }
    }
    priority_queue<pll,vector<pll>,greater<pll> > pq;
    pq.push(mp(0,1));
    fill(dis,dis+4*n+10,-1);
    while(!pq.empty()){
        pll p=pq.top();
        pq.pop();
        if(dis[p.y]!=-1)continue;
        dis[p.y]=p.x;
        for(auto it:v[p.y]){
            if(dis[it.x]==-1){
                pq.push(mp(p.x+it.y,it.x));
            }
        }
    }
    for(int i = 2;i<=n;i++){
        printf("%lld ",dis[i+3*n]);
    }
    printf("\n");
}
int main(){
    int t=1;//00000;
  //  scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/