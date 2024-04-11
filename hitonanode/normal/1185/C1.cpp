#include <iostream>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)

int tc[101];
int solve(int M)
{
    int ret = 0;
    IFOR(t, 1, 101)
    {
        int nadd = max(0, min((-M + t - 1) / t, tc[t]));
        M += nadd * t;
        ret += nadd;
    }
    return ret;
}

int main()
{
    int N, M, t;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> t;
        M -= t;
        cout << solve(M) << " ";
        tc[t]++;
    }
    cout << endl;
}