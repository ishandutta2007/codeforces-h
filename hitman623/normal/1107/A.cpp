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
string s;
int n;
void solve(){
    cin>>n>>s;
    if(n>2){
        cout<<"YES"<<endl;
        cout<<2<<endl;
        cout<<s[0]<<" ";
        rep(i,1,n) cout<<s[i];
        cout<<endl;
    }
    else if(s[1]>s[0]){
        cout<<"YES"<<endl;
        cout<<2<<endl;
        cout<<s[0]<<" "<<s[1]<<endl;
    }
    else cout<<"NO"<<endl;
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