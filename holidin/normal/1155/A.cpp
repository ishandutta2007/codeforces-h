#include <bits/stdc++.h>
#pragma GCC optimize 03
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;

int main() {
    string s;
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for (i = 0; i < s.size() - 1; ++i)
    if (s[i] > s[i + 1]) {
        cout << "YES\n";
        cout << i + 1 << ' ' << i + 2 << endl;
        exit(0);
    }
    cout << "NO";
}