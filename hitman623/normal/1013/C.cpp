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
#define hell        1000000000000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[200005],ans=hell,mn=hell;
void solve(){
    cin>>n;
    rep(i,0,2*n) cin>>a[i];
    sort(a,a+2*n);
    rep(i,0,n) mn=min(mn,a[i+n-1]-a[i]);
    ans=min(ans,(a[n-1]-a[0])*(a[2*n-1]-a[n]));
    ans=min(ans,(a[2*n-1]-a[0])*mn);
    cout<<max(0LL,ans)<<endl;
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