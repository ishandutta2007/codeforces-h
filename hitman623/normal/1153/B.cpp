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
int n,m,h,row[101],col[101],a[101][101];
void solve(){
    cin>>n>>m>>h;
    rep(i,0,m) cin>>col[i];
    rep(i,0,n) cin>>row[i];
    rep(i,0,n){
    	rep(j,0,m){
    		cin>>a[i][j];
    	}
    }
    rep(i,0,n){
    	rep(j,0,m){
    		if(a[i][j]) a[i][j]=min(row[i],col[j]);
    		cout<<a[i][j]<<" ";
    	}
    	cout<<endl;
    }
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