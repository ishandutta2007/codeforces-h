#include <bits/stdc++.h>
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

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    lint N, M;
    cin >> N >> M;
    vector<vector<pint>> to(N);
    int all_xor = 0;
    vector<tuple<int, int, int>> edges;

    vector<int> deg(N);
    REP(_, M) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        to[u].emplace_back(v, w);
        to[v].emplace_back(u, w);
        all_xor ^= w;
        edges.emplace_back(w, u, v);
        deg[u]++;
        deg[v]++;
    }

    REP(i, N) sort(ALL(to[i]));

    lint n_free = lint(N) * (N - 1) / 2 - M - 1;

    edges.emplace_back(0, 0, 0);
    sort(ALL(edges));

    int ncon = N;
    lint ret = 1LL << 60;

    UnionFind uf1(N);

    int ns = N;
    vector<int> is(N);
    iota(ALL(is), 0);
    shuffle(is.begin(), is.end(), rng);

    dbg(to);
    for (auto i : is) {
        int cur = 0;
        for (auto [j, w] : to[i]) {
            FOR(k, cur, j) {
                if (uf1.unite(i, k)) ns--;
            }
            cur = j + 1;
        }
        FOR(k, cur, N) {
            if (uf1.unite(i, k)) ns--;
        }
        if (ns <= 600) break;
    }

    {
        vector<int> roots;
        REP(i, N) roots.emplace_back(uf1.find(i));
        roots = sort_unique(roots);
        const int D = roots.size();
        assert(D == ns);
        vector A(D, vector<lint>(D));
        vector<lint> szz;
        for (auto r : roots) szz.emplace_back(uf1.count(r));
        for (auto [w, i, j] : edges) {
            int a = lower_bound(ALL(roots), uf1.find(i)) - roots.begin();
            int b = lower_bound(ALL(roots), uf1.find(j)) - roots.begin();
            A[a][b]++, A[b][a]++;
        }
        REP(d, D) REP(e, d) {
            if (szz[d] * szz[e] > A[d][e]) uf1.unite(roots[d], roots[e]);
        }
    }

    UnionFind uf(N);

    lint cost = 0;
    for (auto [w, a, b] : edges) if (uf1.unite(a, b)) {
        cost += w;
        uf.unite(a, b);
        ncon--;
    }
    for (auto [w, a, b] : edges) {
        if (uf.unite(a, b)) {
            cost += w;
            ncon--;
        }
        if (ncon - 1 <= n_free) chmin(ret, cost);
        if (ncon - 1 <= n_free + 1) chmin(ret, cost + all_xor);
    }
    cout << ret << '\n';
}