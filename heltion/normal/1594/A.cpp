#include <bits/stdc++.h> 
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n;
        cin >> n;
        if (n == 0) cout << "-1 1\n";
        else cout << -n + 1 << " " << n << "\n";
    }
    return 0;
}