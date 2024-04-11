/**   Created by: Humberto Yusta
      Codeforces User: humbertoyusta
      Country: Cuba
      Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<59ll)-1ll)*2ll)+1ll;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lgx(x,b) ( log(x) / log(b) )
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Pow------------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    int pwur = qpow(b,e>>1);
    return ( pwur * pwur ) % mod * ( b * ( e & 1 ) ) % mod;
}
/// My Code -------------------------------------------------

int n, sum, a[maxn], b[maxn];

int solve(int t){
    for(int i=1; i<=n; i++)
        b[i] = a[i];
    int res = 0;
    int tmp = 0;
    for(int i=1; i<=n; i++){
        if( tmp < t / 2 ){
            int nxt = min( b[i] , ( t - 1 ) / 2 - tmp );
            res -= i * nxt;
            tmp += nxt;
            b[i] -= nxt;
        }
        if( tmp == ( t - 1 ) / 2 && b[i] ){
            tmp++;
            if( t == 2 ) res -= i;
            b[i]--;
        }
        if( tmp >= ( t + 1 ) / 2 ){
            int nx2 = min( t - tmp , b[i] );
            res += i * nx2;
            tmp += nx2;
            b[i] -= nx2;
        }
        if( tmp == t ){
            tmp = 0;
            b[i] = b[i] % t;
                if( tmp < t / 2 ){
                    int nxt = min( b[i] , ( t - 1 ) / 2 - tmp );
                    res -= i * nxt;
                    tmp += nxt;
                    b[i] -= nxt;
                }
                if( tmp == ( t - 1 ) / 2 && b[i] ){
                    tmp++;
                    if( t == 2 ) res -= i;
                    b[i]--;
                }
                if( tmp >= ( t + 1 ) / 2 ){
                    int nx2 = min( t - tmp , b[i] );
                    res += i * nx2;
                    tmp += nx2;
                    b[i] -= nx2;
                }
            if( tmp == t )
                tmp = 0;
        }
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }

    int ans = INF;
    for(int i=2; i*i<=sum; i++){
        if( sum % i == 0 ){
            ans = min( ans , solve(i) );
            while( sum % i == 0 ) sum /= i;
        }
    }
    if( sum != 1 )
        ans = min( ans , solve(sum) );

    if( ans == INF ) ans = -1;
    cout << ans << '\n';

    return 0;
}