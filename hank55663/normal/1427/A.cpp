#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[55];
    int sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum==0){
        printf("NO\n");
    }
    else{
        vector<int> pos,neg;
        for(int i = 0;i<n;i++){
            if(a[i]>0)pos.pb(a[i]);
            if(a[i]<0)neg.pb(a[i]);
        }
        vector<int> b;
        if(sum<0)swap(pos,neg);
        for(auto it:pos)b.pb(it);
        for(auto it:neg)b.pb(it);
        while(b.size()<n)b.pb(0);
        printf("YES\n");
        for(auto it:b){
            printf("%d ",it);
        }
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*


*/
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/