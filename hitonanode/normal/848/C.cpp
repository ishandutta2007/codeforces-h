#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
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
#include <type_traits>
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
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
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
#define dbgif(cond, x) ((cond) ? cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl : cerr)
#else
#define dbg(x) (x)
#define dbgif(cond, x) 0
#endif

// 
template <class S, void (*opadd)(S &, S), void (*opsub)(S &, S), S (*e)(), class Coordinate> class rangetree {
    int n;
    std::vector<std::pair<Coordinate, Coordinate>> _pts;
    struct BIT {
        std::vector<S> data;
        BIT(int len) : data(len, e()) {}
        void add(int pos, S v) {
            for (pos++; pos and pos <= int(data.size()); pos += pos & -pos) opadd(data[pos - 1], v);
        }
        S sum(int r) const {
            S ret = e();
            while (r) opadd(ret, data[r - 1]), r -= r & -r;
            return ret;
        }
    };

    std::vector<std::vector<Coordinate>> _range2ys;
    std::vector<BIT> bits;
    void _add_singlenode(int v, Coordinate y, S val) {
        auto i = std::distance(_range2ys[v].begin(), std::lower_bound(_range2ys[v].begin(), _range2ys[v].end(), y));
        bits[v].add(i, val);
    }
    S _get_singlenode(int v, Coordinate y) const {
        auto i = std::distance(_range2ys[v].begin(), std::lower_bound(_range2ys[v].begin(), _range2ys[v].end(), y));
        return bits[v].sum(i);
    }
    S _sum(Coordinate xl, Coordinate xr, Coordinate yr) const { // [xl, xr) * (-INF, yr)
        auto compx = [](std::pair<Coordinate, Coordinate> l, std::pair<Coordinate, Coordinate> r) {
            return l.first < r.first;
        };
        int l = n + std::distance(_pts.begin(), std::lower_bound(_pts.begin(), _pts.end(), std::make_pair(xl, yr), compx));
        int r = n + std::distance(_pts.begin(), std::lower_bound(_pts.begin(), _pts.end(), std::make_pair(xr, yr), compx));
        S ret = e();
        while (l < r) {
            if (l & 1) opadd(ret, _get_singlenode(l++, yr));
            if (r & 1) opadd(ret, _get_singlenode(--r, yr));
            l >>= 1, r >>= 1;
        }
        return ret;
    }

public:
    rangetree() = default;
    void add_point(Coordinate x, Coordinate y) noexcept { _pts.emplace_back(x, y); }
    void build() {
        std::sort(_pts.begin(), _pts.end());
        _pts.erase(std::unique(_pts.begin(), _pts.end()), _pts.end());
        n = _pts.size();

        _range2ys.resize(n * 2);
        for (int i = 0; i < n; i++) _range2ys[n + i] = {_pts[i].second};
        for (int i = n - 1; i > 0; i--) {
            auto &lch = _range2ys[i * 2];
            auto &rch = _range2ys[i * 2 + 1];
            std::merge(lch.begin(), lch.end(), rch.begin(), rch.end(), std::back_inserter(_range2ys[i]));
            _range2ys[i].erase(std::unique(_range2ys[i].begin(), _range2ys[i].end()), _range2ys[i].end());
        }
        for (const auto &v : _range2ys) bits.push_back(BIT(v.size()));
    }
    void add(Coordinate x, Coordinate y, S val) {
        int i = std::distance(_pts.begin(), std::lower_bound(_pts.begin(), _pts.end(), std::make_pair(x, y)));
        assert(i < n and _pts[i] == std::make_pair(x, y));
        for (i += n; i; i >>= 1) _add_singlenode(i, y, val);
    }
    S sum(Coordinate xl, Coordinate xr, Coordinate yl, Coordinate yr) const {
        auto ret_r = _sum(xl, xr, yr);
        auto ret_l = _sum(xl, xr, yl);
        opsub(ret_r, ret_l);
        return ret_r;
    }
};

using S = unsigned long long;
S e() noexcept { return 0; } // 
void opadd(S &l, S r) noexcept { l += r; }
void opsub(S &l, S r) noexcept { l -= r; }

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    cin >> A;
    vector<int> Q(M), P(M), X(M);
    vector<set<int>> v2is(N + 1);
    rangetree<unsigned long long, opadd, opsub, e, int> tree;

    vector<tuple<int, int, int, int>> additional_values;
    auto set_val = [&](int t, int x, int y) -> void {
        if (x < 0 or y >= N) return;
        tree.add_point(x, y);
        additional_values.emplace_back(t, x, y, y - x);
    };

    vector<int> current_len(N);
    IREP(i, N) {
        int nxt = i;
        if (v2is[A[i]].size()) {
            int j = *v2is[A[i]].begin();
            set_val(-1, i, j);
            current_len[i] = j - i;
        }
        v2is[A[i]].insert(i);
    }

    auto rm_val = [&](int t, int x, int y) -> void {
        if (x < 0 or y >= N) return;
        additional_values.emplace_back(t, x, y, -(y - x));
    };
    constexpr int ADD = 100, ERASE = 200;

    REP(i, M) {
        cin >> Q[i] >> P[i] >> X[i];
        P[i]--;
        if (Q[i] == 1) {
            int x = P[i], a = A[x];
            v2is[a].erase(x);
            int aprv = -1, anxt = N;
            auto itr = v2is[a].upper_bound(x);
            if (itr != v2is[a].end()) anxt = *itr;
            if (v2is[a].size() and *v2is[a].begin() < x) aprv = *prev(v2is[a].lower_bound(x));
            if (aprv >= 0) {
                rm_val(i, aprv, x);
                current_len[aprv] = 0;
            }
            if (anxt < N) {
                rm_val(i, x, anxt);
                current_len[x] = 0;
                if (aprv >= 0) {
                    current_len[aprv] = anxt - aprv;
                    set_val(i, aprv, anxt);
                }
            }
            dbg(pint(aprv, anxt));

            a = X[i];
            A[x] = a;
            aprv = -1, anxt = N;
            itr = v2is[a].upper_bound(x);
            if (itr != v2is[a].end()) anxt = *itr;
            if (v2is[a].size() and *v2is[a].begin() < x) aprv = *prev(v2is[a].lower_bound(x));
            v2is[a].insert(x);
            dbg(pint(aprv, anxt));

            if (aprv >= 0) {
                if (anxt < N) {
                    rm_val(i, aprv, anxt);
                }
                current_len[aprv] = x - aprv;
                set_val(i, aprv, x);
            }
            if (anxt < N) {
                current_len[x] = anxt - a;
                set_val(i, x, anxt);
            }
        }
        dbg(A);
    }
    tree.build();
    dbg(additional_values);
    int cur = 0;
    REP(q, M) {
        while (cur < int(additional_values.size()) and get<0>(additional_values[cur]) <= q) {
            auto [tm, x, y, v] = additional_values[cur++];
            tree.add(x, y, v);
        }
        if (Q[q] == 2) {
            auto ret = tree.sum(P[q], X[q], P[q], X[q]);
            cout << ret << '\n';
        }
    }
}