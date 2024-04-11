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
const int maxn = 10010;
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
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
/// My Code -------------------------------------------------

int tc, n, m;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while( tc-- ){
        cin >> n;
        if( n == 2 ){ cout << 1 << '\n' << 0 << '\n'; continue; }
        if( n == 3 ){ cout << 1 << '\n' << 1 << '\n'; continue; }
        cout << (int)(log2(n)) << '\n';
        if( __builtin_popcountll(n) == 1 ){
            for(int i=0; i<(int)(log2(n))-2; i++){
                cout << (1ll<<i) << ' ';
            }
            cout << 0 << ' ' << 1 << '\n';
            continue;
        }
        for(int i=0; i<(int)(log2(n))-2; i++){
            cout << (1ll<<i) << ' ';
        }
        int tmp = n - ( 1ll << ((int)(log2(n))) );
        if( tmp ) tmp++;
        if( tmp / 2 < (1ll<<((int)(log2(n))-2)) ) cout << tmp/2 << ' ' << tmp%2 << '\n';
        else{
            cout << (1ll<<((int)(log2(n)-2))) << ' ' << ( tmp - ( 1ll << ((int)(log2(n))-1) ) ) << '\n';
        }
    }

    return 0;
}