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
string s,w="twone";
void solve(){
    vi ans;
    cin>>s;
    rep(i,0,sz(s)-4){
        if(s.substr(i,5)==w){
            ans.pb(i+2);
            s[i+2]='#';
        }
    }
    rep(i,0,sz(s)-2){
        if(s.substr(i,3)=="two"){
            ans.pb(i+1);
            s[i+1]='#';
        }
        if(s.substr(i,3)=="one"){
            ans.pb(i+1);
            s[i+1]='#';
        }
    }
    cout<<sz(ans)<<endl;
    for(auto i:ans) cout<<i+1<<" ";
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}