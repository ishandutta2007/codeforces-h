#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

string s,t;

bool check(){
	cin>>s;
	t=s;
	reverse(ALL(t));
	if(t!=s) return false;
	
	REP(i,s.size()){
		if(s[i]=='A' || s[i]=='H' || s[i]=='I' || s[i]=='M' || s[i]=='O' ||
			s[i]=='T' || s[i]=='U' || s[i]=='V' || s[i]=='W' || 
			s[i]=='X' || s[i]=='Y');
		else return false;
	}
	return true;
}
int main(){
	if(check()) puts("YES");
	else puts("NO");

	return 0;
}