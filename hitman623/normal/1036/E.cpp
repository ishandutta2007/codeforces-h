#include <bits/stdc++.h>

#define int         long long
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
template <class T>
struct Point 
{
    typedef Point P;
    T x, y;
    explicit Point(T x1=0, T y1=0) : x(x1), y(y1) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-* this).cross(b-* this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to xaxis in interval [pi , pi ]
    double angle() const { return atan2(y, x); }
    P unit() const { return * this/dist(); } // makes d i s t ()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated a  radians ccw around the origin
    P rotate(double a) const { return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};
typedef Point<double> P;
int segment_Intersection(const P& s1, const P& e1,const P& s2, const P& e2, P& r1, P& r2){
    if(e1==s1){
        if(e2==s2){
            if(e1==e2){
                r1=e1;
                return 1; 
            }
            else return 0;
        }
        else return segment_Intersection(s2,e2,s1,e1,r1,r2);
    }
    P v1=e1-s1,v2=e2-s2,d=s2-s1;
    auto a=v1.cross(v2),a1=v1.cross(d),a2=v2.cross(d);
    if(a==0){
        auto b1=s1.dot(v1), c1=e1.dot(v1),b2=s2.dot(v1), c2=e2.dot(v1);
        if(a1 || a2 || max(b1,min(b2,c2))>min(c1,max(b2,c2))) return 0;
        r1 = min(b2,c2)<b1 ? s1 : (b2<c2 ? s2 : e2);
        r2 = max(b2,c2)>c1 ? e1 : (b2>c2 ? s2 : e2);
        return 2-(r1==r2);
    }
    if(a<0){
        a=-a;
        a1=-a1;
        a2=-a2;
    }
    if(0<a1 || a<-a1 || 0<a2 || a<-a2) return 0;
    r1=s1-v1*a2/a;
    return 1;
}
int n,ans;
P a[1001],b[1001];
map<pii,int> mp;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i].x>>a[i].y>>b[i].x>>b[i].y;
        ans+=__gcd((int)abs(a[i].x-b[i].x),(int)abs(a[i].y-b[i].y))+1;
    }
    rep(i,0,n){
        rep(j,i+1,n){
            P e;
            if(segment_Intersection(a[i],b[i],a[j],b[j],e,e)){
                int x=e.x,y=e.y;
                if(e.x==x and e.y==y){
                    mp[{x,y}]+=1;
                }
            }
        }
    }
    for(auto i:mp){
        int d=sqrt(2*i.y);
        while(d*(d-1)/2<i.y) d++;
        ans=ans-d+1;
    }
    cout<<ans<<endl;
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