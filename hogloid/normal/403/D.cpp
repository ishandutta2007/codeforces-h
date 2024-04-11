#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}
const int mod=1000000007;

struct Int {
	unsigned x;
	int mpow(Int a,int k){
		Int res=1;
		while(k){
			if(k&1) res=res*a;
			a=a*a;
			k>>=1;
		}
		return res.x;
	}
	int inverse(Int a){
		return mpow(a,mod-2);
	}
	Int(): x(0) { }
	Int(long long sig) { int sigt = sig % mod; if(sigt < 0) sigt += mod; x = sigt; }
	int get() const { return (int)x; }
	
	Int &operator+=(Int that) { if((x += that.x) >= mod) x -= mod; return *this; }
	Int &operator-=(Int that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
	Int &operator*=(Int that) { x = (unsigned long long)x * that.x % mod; return *this; }
	Int &operator=(Int that) { x=that.x; return *this;}
	Int &operator/=(Int that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
	bool operator==(Int that){ return x==that.x; }
	bool operator>(Int that) { return x>that.x;}
	bool operator<(Int that) { return x<that.x;}


	Int operator+(Int that) const { return Int(*this) += that; }
	Int operator-(Int that) const { return Int(*this) -= that; }
	Int operator*(Int that) const { return Int(*this) *= that; }
	Int operator/(Int that) const { return Int(*this) /= that; }

};



namespace std{
	ostream &operator <<(ostream& out,const Int& a){
		out<<a.get();
		return out;
	}
	istream &operator >>(istream& in,Int& a){
		in>>a.x;
		return in;
	}
};

Int dp[55][1005];
Int ans[55][1005];

Int way[55][1005];
Int fact[1005];

Int C[1505][1505];
int main(){
	REP(i,1500){
		C[i][0]=1;
		REP(j,i) C[i][j+1]=C[i-1][j+1]+C[i-1][j];
	}

	
	fact[0]=1;
	REP(i,1000) fact[i+1]=fact[i]*(i+1);

	for(int k=1;k<=50;++k){
		CLR(dp);
		dp[0][0]=1;
		REP(i,k) REP(j,1001) if(dp[i][j]>0){
			if(i==0 && j==0) dp[i+1][j]+=dp[i][j];
			if(j+(k-i)<=1000) dp[i+1][j+(k-i)]+=dp[i][j];
			if(j+(k-i)<=1000) dp[i][j+(k-i)]+=dp[i][j];
		}
		REP(j,1001) way[k][j]=dp[k][j];
	}
	for(int k=1;k<=50;++k) for(int n=k;n<=1000;++n){
		if(k*(k+1)/2>n) ans[k][n]=0;
		else{
			
			for(int i=k*(k-1)/2;i<=n-k;++i){

				Int tmp=way[k][i]*fact[k];
				int rest=n-i-k;
				if(rest>=0){
					tmp*=C[rest+k][k];
					ans[k][n]+=tmp;
				}

			}
		}
	}

	int t;scanf("%d",&t);
	while(t--){
		int n,k;scanf("%d%d",&n,&k);
		Int res=0;
		if(k*(k+1)/2>n) ;
		else res=ans[k][n];
		printf("%d\n",res.get());
	}

	return 0;
}