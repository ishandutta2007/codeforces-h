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

int k;
int col[1005];

const lint mod=1000000007;
lint dp[1005][1005];
lint C[1005][1005];
int main(){
  cin>>k;
  REP(i,k) cin>>col[i];
  REP(i,1005){
    C[i][0]=1;
    REP(j,i) C[i][j+1]=(C[i-1][j+1]+C[i-1][j])%mod;
  }

  dp[0][0]=1;
  reverse(col,col+k);
  col[k]=1;
  REP(i,k+1) for(int j=1000;j>=0;--j) if(dp[i][j]){
    if(j>0) (dp[i][j-1]+=dp[i][j])%=mod;
    (dp[i+1][j+col[i]-1]+=dp[i][j]*C[j+col[i]-1][j])%=mod;
  }
  cout<<dp[k][0]<<endl;
  return 0;
}