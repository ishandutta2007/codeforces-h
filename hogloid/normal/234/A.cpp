#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
char s[105];
int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>n>>s;
	for(int i=0;i<n/2;++i){
		if(s[i]=='R' && s[i+n/2]=='L') cout<<i+n/2+1<<' '<<i+1<<endl;
		else cout<<i+1<<' '<<i+1+n/2<<endl;
	}

	return 0;
}