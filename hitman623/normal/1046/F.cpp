#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,ans;
priority_queue<int> pq;
void solve(){
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        pq.push(x);
    }
    int x,f;
    cin>>x>>f;
    while(!pq.empty()){
        auto d=pq.top();
        pq.pop();
        if(d<=x) break;
        int h=d/(x+f);
        ans+=f*h;
        d%=(x+f);
        if(d<=x) continue;
        ans+=f;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}