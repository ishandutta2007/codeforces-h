    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
/// Constraints:
const int maxn = 1000010;
const int mod2 = 1000000007;
const int mod = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Functions------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
mt19937_64 r(time(0));
int rng (int a, int b){
    return uniform_int_distribution<int>(a,b)(r);
}
/// My Code -------------------------------------------------

int par[maxn], pr[maxn];

vector<int> fact(int x){
    vector<int> fc;
    while( x > 1 ){
        if( fc.empty() || pr[x] != fc.back() )
            fc.pb(pr[x]);
        x /= pr[x];
    }
    return fc;
}

int find_(int x){
    return ( par[x] == x ) ? ( x ) : ( par[x] = find_( par[x] ) );
}

void union_(int x,int y){
    x = find_(x), y = find_(y);
    if( x == y ) return;
    par[y] = x;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    for(int i=1; i<maxn; i++)
        pr[i] = i;
    for(int i=2; i<maxn; i++)
        if( pr[i] == i )
            for(int j=i; j<maxn; j+=i)
                pr[j] = min( pr[j] , i );

    int tc;
    //cin >> tc;
    tc = 1;
    while( tc -- ){

        int n, q;
        cin >> n >> q;

        for(int i=1; i<maxn; i++)
            par[i] = i;

        vector<int> a(n+1), cnt(maxn);
        for(int i=1; i<=n; i++){
            cin >> a[i];
            cnt[a[i]] = 1;
            vector<int> f = fact(a[i]);
            for(int i=0; i<f.size()-1; i++){
                union_(f[i],f[i+1]);
            }
        }

        map<pair<int,int>,bool> mp;
        vector<int> v1 = fact(2);
        for(int i=3; i<maxn-1; i++){
            vector<int> v2 = fact(i);
            if( cnt[i-1] ){
                for( auto i : v1 )
                    for( auto j : v2 ){
                        mp[{find_(i),find_(j)}] = true;
                        mp[{find_(j),find_(i)}] = true;
                    }
                for( auto i : v2 )
                    for( auto j : v2 ){
                        mp[{find_(i),find_(j)}] = true;
                        mp[{find_(j),find_(i)}] = true;
                    }
            }
            v1 = v2;
        }

        for(int i=1; i<=q; i++){
            int s, t;
            cin >> s >> t;
            vector<int> vs = fact(a[s]);
            vector<int> vt = fact(a[t]);

            int ans = 2;
            for( auto i : vs )
                for( auto j : vt ){
                    if( find_(i) == find_(j) ){
                        ans = 0;
                    }
                    if( mp[{find_(i),find_(j)}] ){
                        ans = min( ans , 1ll );
                    }
                }
            cout << ans << '\n';
        }
    }

    return 0;
}