//  Codeforces Beta Round #60

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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const int INF = 1001001001;

int N;
char Y[1010][10], Z[1010][10];
int dp[1010];

int main() {
    int i, j, k;
    int x;
    
    for (; ~scanf("%d", &N); ) {
        for (i = 0; i < N; ++i) {
            scanf("%s", Y[i]);
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (i = 0; i < N; ++i) {
            for (j = 0; j < 4; ++j) {
                for (k = 0; k < 10; ++k) {
                    strcpy(Z[i], Y[i]);
                    Z[i][j] = '0' + k;
                    sscanf(Z[i], "%d", &x);
                    if (1000 <= x && x <= 2011) {
                        if (dp[i] <= x) {
                            chmin(dp[i + 1], x);
                        }
                    }
                }
            }
            if (dp[i + 1] >= INF) {
                goto failed;
            }
        }
        for (i = 0; i < N; ++i) {
            printf("%d\n", dp[i + 1]);
        }
        continue;
    failed:;
        puts("No solution");
    }
    
    return 0;
}