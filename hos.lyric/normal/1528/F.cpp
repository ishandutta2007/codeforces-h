#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }


////////////////////////////////////////////////////////////////////////////////
template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
constexpr unsigned MO = 998244353U;
constexpr unsigned MO2 = 2U * MO;
constexpr int FFT_MAX = 23;
using Mint = ModInt<MO>;
constexpr Mint FFT_ROOTS[FFT_MAX + 1] = {1U, 998244352U, 911660635U, 372528824U, 929031873U, 452798380U, 922799308U, 781712469U, 476477967U, 166035806U, 258648936U, 584193783U, 63912897U, 350007156U, 666702199U, 968855178U, 629671588U, 24514907U, 996173970U, 363395222U, 565042129U, 733596141U, 267099868U, 15311432U};
constexpr Mint INV_FFT_ROOTS[FFT_MAX + 1] = {1U, 998244352U, 86583718U, 509520358U, 337190230U, 87557064U, 609441965U, 135236158U, 304459705U, 685443576U, 381598368U, 335559352U, 129292727U, 358024708U, 814576206U, 708402881U, 283043518U, 3707709U, 121392023U, 704923114U, 950391366U, 428961804U, 382752275U, 469870224U};
constexpr Mint FFT_RATIOS[FFT_MAX - 1] = {911660635U, 509520358U, 369330050U, 332049552U, 983190778U, 123842337U, 238493703U, 975955924U, 603855026U, 856644456U, 131300601U, 842657263U, 730768835U, 942482514U, 806263778U, 151565301U, 510815449U, 503497456U, 743006876U, 741047443U, 56250497U, 867605899U};
constexpr Mint INV_FFT_RATIOS[FFT_MAX - 1] = {86583718U, 372528824U, 373294451U, 645684063U, 112220581U, 692852209U, 155456985U, 797128860U, 90816748U, 860285882U, 927414960U, 354738543U, 109331171U, 293255632U, 535113200U, 308540755U, 121186627U, 608385704U, 438932459U, 359477183U, 824071951U, 103369235U};

// as[rev(i)] <- \sum_j \zeta^(ij) as[j]
void fft(Mint *as, int n) {
  assert(!(n & (n - 1))); assert(1 <= n); assert(n <= 1 << FFT_MAX);
  int m = n;
  if (m >>= 1) {
    for (int i = 0; i < m; ++i) {
      const unsigned x = as[i + m].x;  // < MO
      as[i + m].x = as[i].x + MO - x;  // < 2 MO
      as[i].x += x;  // < 2 MO
    }
  }
  if (m >>= 1) {
    Mint prod = 1;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + m; ++i) {
        const unsigned x = (prod * as[i + m]).x;  // < MO
        as[i + m].x = as[i].x + MO - x;  // < 3 MO
        as[i].x += x;  // < 3 MO
      }
      prod *= FFT_RATIOS[__builtin_ctz(++h)];
    }
  }
  for (; m; ) {
    if (m >>= 1) {
      Mint prod = 1;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + m; ++i) {
          const unsigned x = (prod * as[i + m]).x;  // < MO
          as[i + m].x = as[i].x + MO - x;  // < 4 MO
          as[i].x += x;  // < 4 MO
        }
        prod *= FFT_RATIOS[__builtin_ctz(++h)];
      }
    }
    if (m >>= 1) {
      Mint prod = 1;
      for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
        for (int i = i0; i < i0 + m; ++i) {
          const unsigned x = (prod * as[i + m]).x;  // < MO
          as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;  // < 2 MO
          as[i + m].x = as[i].x + MO - x;  // < 3 MO
          as[i].x += x;  // < 3 MO
        }
        prod *= FFT_RATIOS[__builtin_ctz(++h)];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;  // < 2 MO
    as[i].x = (as[i].x >= MO) ? (as[i].x - MO) : as[i].x;  // < MO
  }
}

// as[i] <- (1/n) \sum_j \zeta^(-ij) as[rev(j)]
void invFft(Mint *as, int n) {
  assert(!(n & (n - 1))); assert(1 <= n); assert(n <= 1 << FFT_MAX);
  int m = 1;
  if (m < n >> 1) {
    Mint prod = 1;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + m; ++i) {
        const unsigned long long y = as[i].x + MO - as[i + m].x;  // < 2 MO
        as[i].x += as[i + m].x;  // < 2 MO
        as[i + m].x = (prod.x * y) % MO;  // < MO
      }
      prod *= INV_FFT_RATIOS[__builtin_ctz(++h)];
    }
    m <<= 1;
  }
  for (; m < n >> 1; m <<= 1) {
    Mint prod = 1;
    for (int h = 0, i0 = 0; i0 < n; i0 += (m << 1)) {
      for (int i = i0; i < i0 + (m >> 1); ++i) {
        const unsigned long long y = as[i].x + MO2 - as[i + m].x;  // < 4 MO
        as[i].x += as[i + m].x;  // < 4 MO
        as[i].x = (as[i].x >= MO2) ? (as[i].x - MO2) : as[i].x;  // < 2 MO
        as[i + m].x = (prod.x * y) % MO;  // < MO
      }
      for (int i = i0 + (m >> 1); i < i0 + m; ++i) {
        const unsigned long long y = as[i].x + MO - as[i + m].x;  // < 2 MO
        as[i].x += as[i + m].x;  // < 2 MO
        as[i + m].x = (prod.x * y) % MO;  // < MO
      }
      prod *= INV_FFT_RATIOS[__builtin_ctz(++h)];
    }
  }
  if (m < n) {
    for (int i = 0; i < m; ++i) {
      const unsigned y = as[i].x + MO2 - as[i + m].x;  // < 4 MO
      as[i].x += as[i + m].x;  // < 4 MO
      as[i + m].x = y;  // < 4 MO
    }
  }
  const Mint invN = Mint(n).inv();
  for (int i = 0; i < n; ++i) {
    as[i] *= invN;
  }
}

void fft(vector<Mint> &as) {
  fft(as.data(), as.size());
}
void invFft(vector<Mint> &as) {
  invFft(as.data(), as.size());
}

vector<Mint> convolve(vector<Mint> as, vector<Mint> bs) {
  if (as.empty() || bs.empty()) return {};
  const int len = as.size() + bs.size() - 1;
  int n = 1;
  for (; n < len; n <<= 1) {}
  as.resize(n); fft(as);
  bs.resize(n); fft(bs);
  for (int i = 0; i < n; ++i) as[i] *= bs[i];
  invFft(as);
  as.resize(len);
  return as;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// inv: log, exp, pow
constexpr int LIM_INV = 1 << 20;  // @
Mint inv[LIM_INV], fac[LIM_INV], invFac[LIM_INV];
struct ModIntPreparator {
  ModIntPreparator() {
    inv[1] = 1;
    for (int i = 2; i < LIM_INV; ++i) inv[i] = -((Mint::M / i) * inv[Mint::M % i]);
    fac[0] = 1;
    for (int i = 1; i < LIM_INV; ++i) fac[i] = fac[i - 1] * i;
    invFac[0] = 1;
    for (int i = 1; i < LIM_INV; ++i) invFac[i] = invFac[i - 1] * inv[i];
  }
} preparator;
////////////////////////////////////////////////////////////////////////////////


Int N;
int K;

int main() {
  for (; ~scanf("%lld%d", &N, &K); ) {
    vector<Mint> fs(K + 1), gs(K + 1);
    for (int i = 0; i <= K; ++i) {
      fs[i] = invFac[i] * ((i & 1) ? -1 : +1);
      gs[i] = invFac[i] * Mint(i).pow(K);
    }
    const auto S = convolve(fs, gs);
// if(K<=10){cerr<<"S = ";pv(S.begin(),S.end());}
    
    Mint ans = 0;
    Mint fall = 1;
    for (int i = 0; i <= K; ++i) {
      if (N - i < 0) {
        break;
      }
      ans += S[i] * Mint(N + 1).pow(N - i) * fall;
      fall *= (N - i);
    }
    printf("%u\n", ans.x);
  }
  return 0;
}