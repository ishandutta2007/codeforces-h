#include <bits/stdc++.h>

#define ll          long long
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
int n,ans,a[101];
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
    }
    rep(i,1,n+1){
        int cur=a[i];
        rep(j,i,n+1){
            if(a[j]==cur) cur++;
            else break;
        }
        if(cur!=1001) cur--; 
        cur-=a[i];
        if(a[i]!=1) cur--;
        ans=max(ans,cur);
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