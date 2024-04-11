#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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
static const int MAX_V=10000;		
int V;		

struct edge{
	int to,cap,cost,rev;
	edge(int st,int sc,int sco,int sr){
		to=st;cap=sc;cost=sco;rev=sr;
	}
};
vector<edge> g[MAX_V];
int h[MAX_V],dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost){
	g[from].pb(edge(to,cap,cost,g[to].size()));
	g[to].pb(edge(from,0,-cost,g[from].size()-1));
}

int min_cost_flow(int s,int t,int f){
	int res=0;
	fill(h,h+V,0);
	while(f>0){
		priority_queue<pi,vector<pi>,greater<pi> >pq;pq.push(mp(0,s));
		fill(dist,dist+V,INF);
		dist[s]=0;
		while(!pq.empty()){
			pi cur=pq.top();pq.pop();
			if(dist[cur.sc]<cur.fr) continue;
			REP(i,g[cur.sc].size()){
				edge& e=g[cur.sc][i];
				if(e.cap>0 && dist[e.to]>cur.fr+e.cost+h[cur.sc]-h[e.to]){
					dist[e.to]=cur.fr+e.cost+h[cur.sc]-h[e.to];
					prevv[e.to]=cur.sc;
					preve[e.to]=i;
					pq.push(mp(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==INF){
			return -1;
		}
		for(int v=0;v<V;++v) h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,g[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge& e=g[prevv[v]][preve[v]];
			e.cap-=d;
			g[v][e.rev].cap+=d;
		}
	}
	return res;
}


int n,m;
int buf[100][100];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int main(){
	cin>>n>>m;
	REP(i,n) REP(j,m) cin>>buf[i][j];
		
	int S=n*m,T=S+1;
	V=T+1;
	REP(i,n) REP(j,m){
		if((i+j)&1){
			REP(d,4){
				int px=j+dx[d],py=i+dy[d];
				if(py<0 || px<0 || py>=n || px>=m) continue;
				
				add_edge(i*m+j,py*m+px,1,!(buf[py][px]==buf[i][j]));
			}
			add_edge(S,i*m+j,1,0);
		}else add_edge(i*m+j,T,1,0);
	}
	int res=min_cost_flow(S,T,n*m/2);

	printf("%d\n",res);


	return 0;
}