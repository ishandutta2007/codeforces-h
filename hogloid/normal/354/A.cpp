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

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

//const int INF=5e8;

int ar[100005];
int n;
int Lcost,Rcost,Ql,Qr;
int main(){
	cin>>n>>Lcost>>Rcost>>Ql>>Qr;
	REP(i,n) scanf("%d",&ar[i]);

	int R=accumulate(ar,ar+n,0),L=0;

	int res=2e9+10;
	REP(i,n+1){
		int dif=(n-i)-i;
		if(dif>1){
			--dif;
			chmin(res,R*Rcost+L*Lcost+Qr*dif);
		}else if(dif<-1){
			dif*=-1;
			--dif;
			chmin(res,R*Rcost+L*Lcost+Ql*dif);
		}else{
			chmin(res,R*Rcost+L*Lcost);
		}

		L+=ar[i];
		R-=ar[i];

	}
	cout<<res<<endl;
	return 0;
}