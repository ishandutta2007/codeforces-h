#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    int tc;
    cin >> tc;
    while( tc--){
        int a, b, c, d, e, f;
        cin >> a >> b >> e >> f;
        if( a > b ) swap( a , b );
        c = e - f;
        d = e + f;
        c = max( c , a );
        d = min( d , b );
        if( c > d ) c = d;
        cout << ( b - d ) + ( c - a ) << '\n';
    }

    return 0;
}