#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#else
#define dbg(x) (x)
#endif

// Linear sieve algorithm for fast prime factorization
// Complexity: O(N) time, O(N) space:
// - MAXN = 10^7:  ~44 MB,  80~100 ms (Codeforces / AtCoder GCC, C++17)
// - MAXN = 10^8: ~435 MB, 810~980 ms (Codeforces / AtCoder GCC, C++17)
// Reference:
// [1] D. Gries, J. Misra, "A Linear Sieve Algorithm for Finding Prime Numbers,"
//     Communications of the ACM, 21(12), 999-1003, 1978.
// - https://cp-algorithms.com/algebra/prime-sieve-linear.html
// - https://37zigen.com/linear-sieve/
struct Sieve {
    std::vector<int> min_factor;
    std::vector<int> primes;
    Sieve(int MAXN) : min_factor(MAXN + 1) {
        for (int d = 2; d <= MAXN; d++) {
            if (!min_factor[d]) {
                min_factor[d] = d;
                primes.emplace_back(d);
            }
            for (const auto &p : primes) {
                if (p > min_factor[d] or d * p > MAXN) break;
                min_factor[d * p] = p;
            }
        }
    }
    // Prime factorization for 1 <= x <= MAXN^2
    // Complexity: O(log x)           (x <= MAXN)
    //             O(MAXN / log MAXN) (MAXN < x <= MAXN^2)
    template <typename T> std::map<T, int> factorize(T x) {
        std::map<T, int> ret;
        assert(x > 0 and x <= ((long long)min_factor.size() - 1) * ((long long)min_factor.size() - 1));
        for (const auto &p : primes) {
            if (x < T(min_factor.size())) break;
            while (!(x % p)) x /= p, ret[p]++;
        }
        if (x >= T(min_factor.size())) ret[x]++, x = 1;
        while (x > 1) ret[min_factor[x]]++, x /= min_factor[x];
        return ret;
    }
    // Enumerate divisors of 1 <= x <= MAXN^2
    // Be careful of highly composite numbers https://oeis.org/A002182/list https://gist.github.com/dario2994/fb4713f252ca86c1254d#file-list-txt
    // (n, (# of div. of n)): 45360->100, 735134400(<1e9)->1344, 963761198400(<1e12)->6720
    template <typename T> std::vector<T> divisors(T x) {
        std::vector<T> ret{1};
        for (const auto p : factorize(x)) {
            int n = ret.size();
            for (int i = 0; i < n; i++) {
                for (T a = 1, d = 1; d <= p.second; d++) {
                    a *= p.first;
                    ret.push_back(ret[i] * a);
                }
            }
        }
        return ret; // NOT sorted
    }
    // Moebius function Table, (-1)^{# of different prime factors} for square-free x
    // return: [0=>0, 1=>1, 2=>-1, 3=>-1, 4=>0, 5=>-1, 6=>1, 7=>-1, 8=>0, ...] https://oeis.org/A008683
    std::vector<int> GenerateMoebiusFunctionTable() {
        std::vector<int> ret(min_factor.size());
        for (unsigned i = 1; i < min_factor.size(); i++) {
            if (i == 1)
                ret[i] = 1;
            else if ((i / min_factor[i]) % min_factor[i] == 0)
                ret[i] = 0;
            else
                ret[i] = -ret[i / min_factor[i]];
        }
        return ret;
    }
    // Calculate [0^K, 1^K, ..., nmax^K] in O(nmax)
    // Note: **0^0 == 1**
    template <typename MODINT> std::vector<MODINT> enumerate_kth_pows(long long K, int nmax) {
        assert(nmax < int(min_factor.size()));
        assert(K >= 0);
        if (K == 0) return std::vector<MODINT>(nmax + 1, 1);
        std::vector<MODINT> ret(nmax + 1);
        ret[0] = 0, ret[1] = 1;
        for (int n = 2; n <= nmax; n++) {
            if (min_factor[n] == n) {
                ret[n] = MODINT(n).pow(K);
            } else {
                ret[n] = ret[n / min_factor[n]] * ret[min_factor[n]];
            }
        }
        return ret;
    }
};
Sieve sieve(1000000);

struct rand_int_ {
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r) {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;


int main() {
    auto START = std::chrono::system_clock::now();
    int N;
    cin >> N;
    vector<lint> A(N);
    cin >> A;
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::shuffle(A.begin(), A.end(), rng);
    if (N <= 16) {
        lint ret = 0;
        REP(S, 1 << N) {
            if (__builtin_popcount(S) * 2 >= N) {
                lint g = 0;
                REP(i, N) if ((S >> i) & 1) g = __gcd(g, A[i]);
                chmax(ret, g);
            }
        }
        cout << ret << '\n';
        return 0;
    }

    map<lint, vector<int>> mp;
    const int B = min(N, 100);
    REP(i, B) {
        auto f = sieve.factorize(A[i]);
        for (auto [p, deg] : f) mp[p].push_back(deg);
    }
    vector<lint> as{1};
    vector<lint> ps, os;
    for (auto [p, hist] : mp) {
        hist.resize(B, 0);
        sort(hist.begin(), hist.end());
        int o = hist[hist.size() / 8 * 7];
        if (o) {
            ps.push_back(p);
            os.push_back(o);
            vector<lint> addv;
            for (__int128 b = p, t = 1; t <= o; b *= p, t++) {
                for (auto x : as) if (x * b <= 1000000000000) addv.push_back(x * b);
            }
            as.insert(as.end(), addv.begin(), addv.end());
        }
    }
    sort(as.begin(), as.end());

    vector<int> dp(as.size());
    for (auto a : A) {
        lint m = 1;
        REP(ip, ps.size()) {
            REP(_, os[ip]) {
                if (a % ps[ip] == 0) m *= ps[ip], a /= ps[ip];
                else break;
            }
        }
        dp[arglb(as, m)]++;
    }
    for (auto p : ps) {
        IREP(i, as.size()) {
            int j = arglb(as, as[i] * p);
            if (j < int(as.size()) and as[j] == as[i] * p) {
                dp[i] += dp[j];
            }
        }
    }

    IREP(i, dp.size()) {
        if (dp[i] * 2 >= N) {
            cout << as[i] << '\n';
            return 0;
        }
    }
}