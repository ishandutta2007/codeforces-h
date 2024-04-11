#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll maxn = 300000;
ll inv[maxn], fac[maxn];

ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll c(ll n, ll m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
    for (ll i = maxn - 2; i >= 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, k;
    cin >> n >> k;
    init();
    if (k >= n) {
        cout << 0;
        return 0;
    }
    if (k == 0) {
        cout << fac[n];
        return 0;
    }
    ll ans = 2 * c(n, n - k) % mod;
    ll tem = 0;
    for (int i = n - k; i >= 1; i--) {
        if ((n - k - i) & 1) {
            tem = (tem + mod - c(n - k, i) * qpow(i, n) % mod) % mod;
        } else {
            tem = (tem + c(n - k, i) * qpow(i, n)) % mod;
        }
    }
    cout << ans * tem % mod;
}