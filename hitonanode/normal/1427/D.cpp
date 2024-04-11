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
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif


void solve()
{
    int N;
    cin >> N;
    vector<int> C(N);
    cin >> C;
    dbg(C);
    vector<vector<int>> ret;

    auto srt = [&](vector<int> v) -> void {
        ret.push_back({});
        for (auto x : v) if (x) ret.back().emplace_back(x);
        if (ret.back().size() <= 1)
        {
            ret.pop_back();
            return;
        }
        vector<vector<int>> vn;
        int l = 0;
        REP(j, v.size())
        {
            int r = l + v[j];
            vector<int> vv;
            FOR(i, l, r) vv.emplace_back(C[i]);
            vn.emplace_back(vv);

            l = r;
        }
        vector<int> rvec;
        reverse(ALL(vn));
        for (auto vec : vn) rvec.insert(rvec.end(), ALL(vec));
        C = rvec;
    };

    bool Status = false;
    REP(i, N)
    {
        if (!Status)
        {
            if (C[i] != i + 1)
            {
                int j = 0;
                while (C[j] != i + 1) j++;
                vector<int> trans;
                REP(_, i) trans.emplace_back(1);
                trans.emplace_back(j + 1 - i);
                int m = accumulate(ALL(trans), 0);
                if (N != m) trans.emplace_back(N - m);
                Status ^= 1;
                srt(trans);
            }
        }
        else
        {
            if (C[N - 1 - i] != i + 1)
            {
                int j = 0;
                while (C[j] != i + 1) j++;
                vector<int> trans;
                if (j) trans.emplace_back(j);
                trans.emplace_back(N - j - i);
                REP(_, i) trans.emplace_back(1);
                Status ^= 1;
                srt(trans);
            }
        }
    }
    dbg(C);

    if (C[0] != 1)
    {
        vector<int> trans(N, 1);
        srt(trans);
    }

    dbg(C);
    cout << ret.size() << '\n';
    for (auto vec : ret)
    {
        cout << vec.size();
        for (auto x : vec) cout << ' ' << x;
        cout << '\n';
    }
}

int main()
{
    solve();
}