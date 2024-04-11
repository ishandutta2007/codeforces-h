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
int n;
int mv[205];
int vis[205];
lint lcm(lint a,lint b){
  return a/__gcd(a,b)*b;
}
int main(){
  cin>>n;
  REP(i,n) cin>>mv[i],--mv[i];

  lint res=1;
  int need=0;
  REP(i,n){
    memset(vis,-1,sizeof(vis));
    int cur=i;
    int cnt=0;
    while(vis[cur]==-1){
      vis[cur]=cnt;
      cur=mv[cur];
      ++cnt;
    }
    int tail=vis[cur],cycle=cnt-tail;
    chmax(need,tail);
    res=lcm(res,cycle);
  }
  lint ans=res;
  while(ans<need) ans+=res;
  cout<<ans<<endl;
  return 0;
}