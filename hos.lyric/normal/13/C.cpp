//  Codeforces Beta Round #13
//  Problem C

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

#define dp _dp[idx0]
#define DP _dp[idx1]
int idx0 = 0, idx1 = 1;

Int Abs(Int x) { return (x < 0) ? -x : x; }

int N;
Int A[5010], as[5010];
Int _dp[2][5010];

int main() {
    int i, j;
    
    N = in();
    for (i = 0; i < N; ++i) {
        A[i] = in();
        as[i] = A[i];
    }
    sort(as, as + N);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            DP[j] = dp[j] + Abs(A[i] - as[j]);
            if (j && DP[j] > DP[j - 1]) DP[j] = DP[j - 1];
        }
        swap(idx0, idx1);
    }
    cout << dp[N - 1] << endl;
    
    return 0;
}