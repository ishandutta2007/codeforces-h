    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2") //Enable AVX
/// Macros:
//#define int long long
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
const int maxn = 5005;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 2000000000000000000ll;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// rng
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int dp[maxn][maxn], mn[maxn][maxn], a[maxn], n;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++){
        mn[i][i] = i;
        for(int j=i+1; j<=n; j++){
            if( a[j] < a[mn[i][j-1]] ) mn[i][j] = j;
                else mn[i][j] = mn[i][j-1];
        }
    }

    for(int i=1; i<=n; i++){
        dp[i][i] = 0;
        int minim = a[i], cnt = 1;
        for(int j=i+1; j<=n; j++){
            if( a[j] == minim ) cnt++;
            if( a[j] < minim ){ minim = a[j], cnt = 1; }
            dp[i][j] = ( j - i + 1 ) - cnt;
        }
    }

    for(int sz=2; sz<=n; sz++){
        for(int i=1; i<=n-sz+1; i++){
            int j = i + sz - 1;
            int k = mn[i][j];//db(i)db(j)//db(k)
            if( k == i ){
                dp[i][j] = min( dp[i][j] , dp[i+1][j] + a[mn[i+1][j]] - a[i] );
                dp[i][j] = min( dp[i][j] , ( j - i ) );
                continue;
            }
            if( k == j ){
                dp[i][j] = min( dp[i][j] , dp[i][j-1] + a[mn[i][j-1]] - a[j] );
                dp[i][j] = min( dp[i][j] , ( j - i ) );
                continue;
            }
            else{
                /// 1
                dp[i][j] = min( dp[i][j] , dp[i][k-1] + a[mn[i][k-1]] - a[k] + dp[k+1][j] + a[mn[k+1][j]] - a[k] );
                /// 2
                dp[i][j] = min( dp[i][j] , ( k - i ) + dp[k+1][j] + a[mn[k+1][j]] - a[k] );
                /// 3
                dp[i][j] = min( dp[i][j] , dp[i][k-1] + a[mn[i][k-1]] - a[k] + ( j - k ) );
                /// 4
                dp[i][j] = min( dp[i][j] , ( k - i ) + ( j - k ) );
            }
            //db(dp[i][j])
        }
    }

    cout << min( n , dp[1][n] + a[mn[1][n]] ) << '\n';

    return 0;
}