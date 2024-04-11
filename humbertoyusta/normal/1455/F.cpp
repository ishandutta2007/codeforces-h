    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2") //Enable AVX
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
const int maxn = 505;
const int mod = 1000000007;
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
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

int tc,n ,k, mk[maxn];
string s, t, dp[maxn];
map<char,char> nxt, prv;

string norm(char a,char b,char c){
    string ans;
    ans += c;
    ans += a;
    ans += b;
    return ans;
}

string best(char a,char b,char c){
    string ans;
    ans += c;
    ans += min( a , min( prv[a] , nxt[a] ) );
    ans += b;
    return ans;
}

string norm(char a,char b){
    string ans;
    ans += b;
    ans += a;
    return ans;
}

string best(char a,char b){
    string ans;
    ans += min( b , min( prv[b] , nxt[b] ) );
    ans += a;
    return ans;
}

string best(char a){
    string ans;
    ans += min( a , min( prv[a] , nxt[a] ) );
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while( tc-- ){

        cin >> n >> k;

        nxt.clear();
        prv.clear();
        for(int i=0; i<k-1; i++)
            nxt[char('a'+i)] = char('a'+i+1);
        nxt[char('a'+k-1)] = 'a';
        for(int i=1; i<k; i++)
            prv[char('a'+i)] = char('a'+i-1);
        prv['a'] = char('a'+k-1);

        cin >> s;
        t.clear();
        dp[0] = "";
        for(int i=1; i<=n; i++)
            dp[i] = char('z'+1);

        for(int i=0; i<=n; i++){
            if( i >= 1 ){
                dp[i] = min( dp[i] , dp[i-1] + best(s[i-1]) );
                int bck = dp[i].back();
                dp[i].pop_back();
                if( i + 1 <= n ) dp[i+1] = min( dp[i+1] , dp[i] + norm( bck , s[i] ) );
                if( i + 2 <= n ) dp[i+2] = min( dp[i+2] , dp[i] + norm( bck , s[i] , s[i+1] ) );
                dp[i] += bck;
            }
            if( i + 2 <= n ) dp[i+2] = min( dp[i+2] , dp[i] + best( s[i] , s[i+1] ) );
            if( i + 3 <= n ) dp[i+3] = min( dp[i+3] , dp[i] + best( s[i] , s[i+1] , s[i+2] ) );
            //db(dp[i])
        }
        cout << dp[n] << '\n';
    }

    return 0;
}