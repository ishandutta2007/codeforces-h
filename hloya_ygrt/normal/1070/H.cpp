//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }

#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }


typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 2e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
const int pp = 41;

#define next ajksdslk

int main() {
//    freopen ("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<string, string> m;
    map<string, int> mtt;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        set<string> vc;
        for (int j = 0; j < s.size(); j ++) {
            for (int k = j; k < s.size(); k ++) {

                string kk = s.substr(j, k - j + 1);
                m[kk] = s;
                vc.insert(kk);
            }
        }
        for (auto & ss : vc) {
            mtt[ss] ++;
        }
    }
    int q;
    cin >> q;
    while (q --) {
        string s;
        cin >> s;

        cout << mtt[s] << " ";
        auto v = m[s] ;
        if (v.empty()) cout << "-\n";
        else cout << v << "\n";

    }
    return 0;

}