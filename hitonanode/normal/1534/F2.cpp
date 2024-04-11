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

// Binary lifting / `Doubling`
// Complexity: O(NlogN) precalculation / O(logN) per query
// <https://atcoder.jp/contests/arc060/submissions/7039451>
struct BinaryLifting {
    int N, INVALID, lgD;
    std::vector<std::vector<int>> mat;
    BinaryLifting() : N(0), lgD(0) {}
    BinaryLifting(const std::vector<int> &vec_nxt, int INVALID = -1, int lgd = 0) : N(vec_nxt.size()), INVALID(INVALID), lgD(lgd) {
        while ((1LL << lgD) < N) lgD++;
        mat.assign(lgD, std::vector<int>(N, INVALID));
        mat[0] = vec_nxt;
        for (int i = 0; i < N; i++)
            if (mat[0][i] < 0 or mat[0][i] >= N) mat[0][i] = INVALID;
        for (int d = 0; d < lgD - 1; d++) {
            for (int i = 0; i < N; i++)
                if (mat[d][i] != INVALID) mat[d + 1][i] = mat[d][mat[d][i]];
        }
    }
    int kth_next(int now, long long k) {
        if (k >= (1LL << lgD)) exit(8);
        for (int d = 0; k and now != INVALID; d++, k >>= 1)
            if (k & 1) now = mat[d][now];
        return now;
    }

    // Distance from l to [r, \infty)
    // Requirement: mat[0][i] > i for all i (monotone increasing)
    int distance(int l, int r) {
        if (l >= r) return 0;
        int ret = 0;
        for (int d = lgD - 1; d >= 0; d--) {
            if (mat[d][l] < r and mat[d][l] != INVALID) ret += 1 << d, l = mat[d][l];
        }
        if (mat[0][l] == INVALID or mat[0][l] >= r)
            return ret + 1;
        else
            return -1; // Unable to reach
    }
};


// Directed graph library to find strongly connected components 
// 0-indexed directed graph
// Complexity: O(V + E)
struct DirectedGraphSCC {
    int V; // # of Vertices
    std::vector<std::vector<int>> to, from;
    std::vector<int> used; // Only true/false
    std::vector<int> vs;
    std::vector<int> cmp;
    int scc_num = -1;

    DirectedGraphSCC(int V = 0) : V(V), to(V), from(V), cmp(V) {}

    void _dfs(int v) {
        used[v] = true;
        for (auto t : to[v])
            if (!used[t]) _dfs(t);
        vs.push_back(v);
    }
    void _rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (auto t : from[v])
            if (!used[t]) _rdfs(t, k);
    }

    void add_edge(int from_, int to_) {
        assert(from_ >= 0 and from_ < V and to_ >= 0 and to_ < V);
        to[from_].push_back(to_);
        from[to_].push_back(from_);
    }

    // Detect strongly connected components and return # of them.
    // Also, assign each vertex `v` the scc id `cmp[v]` (0-indexed)
    int FindStronglyConnectedComponents() {
        used.assign(V, false);
        vs.clear();
        for (int v = 0; v < V; v++)
            if (!used[v]) _dfs(v);
        used.assign(V, false);
        scc_num = 0;
        for (int i = (int)vs.size() - 1; i >= 0; i--)
            if (!used[vs[i]]) _rdfs(vs[i], scc_num++);
        return scc_num;
    }

    // Find and output the vertices that form a closed cycle.
    // output: {v_1, ..., v_C}, where C is the length of cycle,
    //         {} if there's NO cycle (graph is DAG)
    int _c, _init;
    std::vector<int> _ret_cycle;
    bool _dfs_detectcycle(int now, bool b0) {
        if (now == _init and b0) return true;
        for (auto nxt : to[now])
            if (cmp[nxt] == _c and !used[nxt]) {
                _ret_cycle.emplace_back(nxt), used[nxt] = 1;
                if (_dfs_detectcycle(nxt, true)) return true;
                _ret_cycle.pop_back();
            }
        return false;
    }
    std::vector<int> DetectCycle() {
        int ns = FindStronglyConnectedComponents();
        if (ns == V) return {};
        std::vector<int> cnt(ns);
        for (auto x : cmp) cnt[x]++;
        _c = std::find_if(cnt.begin(), cnt.end(), [](int x) { return x > 1; }) - cnt.begin();
        _init = std::find(cmp.begin(), cmp.end(), _c) - cmp.begin();
        used.assign(V, false);
        _ret_cycle.clear();
        _dfs_detectcycle(_init, false);
        return _ret_cycle;
    }

    // After calling `FindStronglyConnectedComponents()`, generate a new graph by uniting all vertices
    // belonging to the same component(The resultant graph is DAG).
    DirectedGraphSCC GenerateTopologicalGraph() {
        DirectedGraphSCC newgraph(scc_num);
        for (int s = 0; s < V; s++)
            for (auto t : to[s]) {
                if (cmp[s] != cmp[t]) newgraph.add_edge(cmp[s], cmp[t]);
            }
        return newgraph;
    }
};



int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    cin >> S;
    vector<int> A(W);
    cin >> A;
    int cnt = 0;
    vector ids(H, vector<int>(W, -1));
    REP(j, W) REP(i, H) { // this order is IMPORTANT
        if (S[i][j] == '#') {
            ids[i][j] = cnt++;
        }
    }
    auto isinner = [&](int i, int j) { return i >= 0 and i < H and j >= 0 and j < W; };

    UnionFind uf(cnt);
    REP(i, H) REP(j, W) {
        array<int, 4> dx{1, -1, 0, 0};
        array<int, 4> dy{0, 0, 1, -1};
        if (S[i][j] != '#') continue;
        REP(d, dx.size()) {
            int ni = i + dx[d], nj = j + dy[d];
            if (isinner(ni, nj) and S[ni][nj] == '#') {
                uf.unite(ids[i][j], ids[ni][nj]);
            }
        }
    }
    vector<int> roots;
    REP(i, cnt) roots.push_back(uf.find(i));
    roots = sort_unique(roots);
    cnt = roots.size();


    REP(i, H) REP(j, W) {
        if (ids[i][j] >= 0) {
            ids[i][j] = arglb(roots, uf.find(ids[i][j]));
        }
    }
    dbg(ids);
    vector<vector<pint>> w2ss(W);
    REP(i, H) REP(j, W) if (ids[i][j] >= 0) w2ss[j].emplace_back(i, ids[i][j]);


    // vector<int> is_hissuid(cnt);
    // vector<int> is_thres(cnt);
    vector<int> LB(W, H);
    // vector<vector<int>> hissu(W);
    vector<int> thres_ids;
    REP(j, W) {
        int yo = -A[j];
        REP(i, H) yo += (S[i][j] == '#');
        REP(i, H) {
            if (S[i][j] == '#') yo--;
            if (yo < 0) {
                if (LB[j] >= H) {
                    // is_thres[ids[i][j]] = 1;
                    thres_ids.push_back(ids[i][j]);
                }
                chmin(LB[j], i);
            }
            if (yo < 0 and ids[i][j] >= 0) {
                // is_hissuid[ids[i][j]] = 1;
            }
        }
    }
    // dbg(is_hissuid);
    // dbg(is_thres);
    dbg(thres_ids);
    thres_ids = sort_unique(thres_ids);
    dbg(thres_ids);
    dbg(LB);

    vector<pint> edges;
    DirectedGraphSCC graph(cnt);
    REP(i, H) REP(j, W) if (ids[i][j] >= 0) {
        int now = ids[i][j];
        for (int jnxt : {j - 1, j, j + 1}) {
            if (!isinner(i, jnxt)) continue;
            auto it1 = lower_bound(ALL(w2ss[jnxt]), pint(i + 1, -1));
            if (it1 != w2ss[jnxt].end()) {
                auto [nxti, nxtid] = *it1;
                if (nxtid != now) { edges.emplace_back(now, nxtid); }
            }
        }
    }
    edges = sort_unique(edges);
    for (auto [s, t] : edges) graph.add_edge(s, t);
    int v2 = graph.FindStronglyConnectedComponents();
    auto g2 = graph.GenerateTopologicalGraph();
    vector<int> isimp2(v2), is_jimei(v2);
    for (auto i : thres_ids) isimp2[graph.cmp[i]] = 1;
    REP(v, v2) {
        if (isimp2[v] or is_jimei[v]) {
            for (auto j : g2.to[v]) is_jimei[j] = 1;
        }
    }
    REP(v, v2) if (is_jimei[v]) isimp2[v] = 0;
    dbg(isimp2);
    dbg(is_jimei);
    vector<int> imp_roots;
    REP(i, v2) if (g2.from[i].empty()) imp_roots.push_back(i);
    dbg(imp_roots);
    vector<int> imp_leaves;
    REP(v, v2) if (isimp2[v]) imp_leaves.push_back(v);
    dbg(imp_leaves);

    vector<int> cmp2ylo(v2, W);
    dbg(graph.cmp);
    REP(i, H) REP(j, W) {
        if (ids[i][j] >= 0) {
            int c = graph.cmp[ids[i][j]];
            chmin(cmp2ylo[c], j);
        }
    }
    dbg(cmp2ylo);
    set<pint> ylo2leaves;
    for (auto v : imp_leaves) ylo2leaves.emplace(cmp2ylo[v], v);
    // for (auto v : imp_leaves) leafylo.push_back(cmp2ylo[v]);
    // dbg(leafylo);
    dbg(ylo2leaves);

    int ret = 0;
    vector<int> cmp_visited(v2);
    while (ylo2leaves.size()) {
        auto [ylonow, qinit] = *ylo2leaves.begin();
        ylo2leaves.erase(ylo2leaves.begin());
        if (cmp_visited[qinit]) continue;
        ret++;
        vector<int> qup, qnow;
        qup.push_back(qinit);
        qnow.push_back(qinit);
        cmp_visited[qinit] = 1;
        while (qnow.size()) {
            auto now = qnow.back();
            qnow.pop_back();
            for (auto nxt : g2.from[now]) {
                if (!cmp_visited[nxt]) {
                    cmp_visited[nxt] = 1;
                    qup.push_back(nxt);
                    qnow.push_back(nxt);
                }
            }
        }
        while (qup.size()) {
            auto now = qup.back();
            qup.pop_back();
            for (auto nxt : g2.to[now]) {
                if (!cmp_visited[nxt]) {
                    cmp_visited[nxt] = 1;
                    qup.push_back(nxt);
                }
            }
        }
    }
    cout << ret << '\n';
}