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
int n,pos=-1;
string s,ss;
void solve(){
    cin>>n>>s;
    int cur=0;
    rep(i,0,n){
    	if(s[i]==')') cur--;
    	else cur++;
    	if(pos==-1 and cur<0){
    		pos=i;
    	}
    }
    if(cur!=0){
    	cout<<"No"<<endl;
    	return;
    }
    if(pos==-1){
    	cout<<"Yes"<<endl;
    	return;
    }
	rep(i,0,n){
		if(i==pos) continue;
		else ss+=s[i];
	}
	ss+=')';
	int w=0;
	rep(i,0,n){
		if(ss[i]==')') w--;
		else w++;
		if(w<0){
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
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