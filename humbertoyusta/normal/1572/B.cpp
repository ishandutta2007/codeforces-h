#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here -------------------------------------



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;
        vector<int> a(n+1);

        int allxor = 0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            allxor ^= a[i];
        }

        if( allxor ){
            cout << "NO\n";
            continue;
        }

        if( n % 2 ){
            cout << "YES\n";
            cout << ( ( n - 2 - 1 ) / 2 + 1 ) * 2 << '\n';
            for(int i=1; i<=n-2; i+=2){
                cout << i << ' ';
            }
            for(int i=n-2; i>=1; i-=2){
                cout << i << ' ';
            }
            cout << '\n';
            continue;
        }

        int xr = 0;
        int solved = 0;
        for(int i=1; i<=n; i++){
            xr ^= a[i];
            if( ( i & 1 ) && ( xr == 0 ) ){
                cout << "YES\n";
                vector<int> ans;
                for(int j=1; j<=i-2; j+=2)
                    ans.push_back(j);
                for(int j=i-2; j>=1; j-=2)
                    ans.push_back(j);

                for(int j=n; j>=i+3; j-=2)
                    ans.push_back(j-2);
                for(int j=i+3; j<=n; j+=2)
                    ans.push_back(j-2);
                cout << ans.size() << '\n';
                for( auto i : ans )
                    cout << i << ' ';
                cout << '\n';
                solved = 1;
                break;
            }
        }

        if( !solved )
            cout << "NO\n";
    }

    return 0;
}