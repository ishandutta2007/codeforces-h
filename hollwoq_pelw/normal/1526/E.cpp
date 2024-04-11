/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
        #ifdef hollwo_pelw_local
            freopen(fileerr.c_str(), "w", stderr);
        #endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out", "error.err");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO(".inp", ".out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

const int N = 2e5 + 5, mod = 998244353;

int fac[N], inv[N];

inline int mul(int a, int b){
    return 1ll * a * b % mod;
}

inline int add(int a, int b){
    return a + b >= mod ? a + b - mod : a + b;
}

struct __initial__ {
    __initial__ () {
        inv[0] = inv[1] = fac[0] = fac[1] = 1;
        for (int i = 2; i < N; i++)
            inv[i] = mod - mul(mod / i, inv[mod % i]);
        for (int i = 2; i < N; i++)
            inv[i] = mul(inv[i - 1], inv[i]), fac[i] = mul(fac[i - 1], i);
    }
} __init__;

int C(int n, int k){
    return (k > n || k < 0) ? 0 : mul(fac[n], mul(inv[n - k], inv[k]));
}

int n, k, a[N], p[N], cnt;

void Hollwo_Pelw() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i], p[a[i]] = i;
    for (int i = 0; i < n - 1; i++){
        if (a[i + 1] < n - 1 && p[a[i] + 1] <= p[a[i + 1] + 1])
            ++ cnt;
    }
    int ans = 0;
    for (int i = 0; i <= cnt; i++)
        ans = add(ans, mul(C(cnt, i), C(k, n - i)));
    cout << ans;
}