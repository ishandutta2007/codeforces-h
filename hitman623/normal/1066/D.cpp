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
int n,m,k,a[200005];
bool check(int mid){
    int cursz=k,cnt=1;
    rep(i,mid,n){
        if(a[i]<=cursz) cursz-=a[i];
        else{
            cnt++;
            cursz=k;
            if(a[i]>cursz) return 0;
            cursz-=a[i];
        }
    }
    return cnt<=m;
}
void solve(){
    cin>>n>>m>>k;
    rep(i,0,n){
        cin>>a[i];
    }
    int lo=0,hi=n;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    if(check(lo)) cout<<n-lo<<endl;
    else cout<<n-hi<<endl;
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