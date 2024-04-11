import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.mathspecial, std.numeric, std.regex, std.typecons;
import core.bitop;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) { throw new EOFException; } tokens = readln.split; } auto token = tokens.front; tokens.popFront; return token; }
int readInt() { return readToken.to!int; }
long readLong() { return readToken.to!long; }
real readReal() { return readToken.to!real; }

bool chmin(T)(ref T t, in T f) { if (t > f) { t = f; return true; } else { return false; } }
bool chmax(T)(ref T t, in T f) { if (t < f) { t = f; return true; } else { return false; } }

int binarySearch(alias pred, T)(in T[] as) { int lo = -1, hi = cast(int)(as.length); for (; lo + 1 < hi; ) { const mid = (lo + hi) >> 1; (unaryFun!pred(as[mid]) ? hi : lo) = mid; } return hi; }
int lowerBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a >= val)); }
int upperBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a > val)); }

struct ModInt {
  static int M;
  import std.conv : to;
  uint x;
  this(ModInt a) { x = a.x; }
  this(uint x_) { x = x_ % M; }
  this(ulong x_) { x = cast(uint)(x_ % M); }
  this(int x_) { x = ((x_ %= cast(int)(M)) < 0) ? (x_ + cast(int)(M)) : x_; }
  this(long x_) { x = cast(uint)(((x_ %= cast(long)(M)) < 0) ? (x_ + cast(long)(M)) : x_); }
  ref ModInt opAssign(T)(inout(T) a) if (is(T == uint) || is(T == ulong) || is(T == int) || is(T == long)) { return this = ModInt(a); }
  ref ModInt opOpAssign(string op, T)(T a) {
    static if (is(T == ModInt)) {
      static if (op == "+") { x = ((x += a.x) >= M) ? (x - M) : x; }
      else static if (op == "-") { x = ((x -= a.x) >= M) ? (x + M) : x; }
      else static if (op == "*") { x = cast(uint)((cast(ulong)(x) * a.x) % M); }
      else static if (op == "/") { this *= a.inv(); }
      else static assert(false);
      return this;
    } else static if (op == "^^") {
      if (a < 0) return this = inv()^^(-a);
      ModInt b = this, c = 1U;
      for (long e = a; e; e >>= 1) { if (e & 1) c *= b; b *= b; }
      return this = c;
    } else {
      return mixin("this " ~ op ~ "= ModInt(a)");
    }
  }
  ModInt inv() const {
    uint a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const q = a / b; const c = a - q * b; a = b; b = c; const w = y - cast(int)(q) * z; y = z; z = w; }
    assert(a == 1); return ModInt(y);
  }
  ModInt opUnary(string op)() const {
    static if (op == "+") { return this; }
    else static if (op == "-") { ModInt a; a.x = x ? (M - x) : 0U; return a; }
    else static assert(false);
  }
  ModInt opBinary(string op, T)(T a) const { return mixin("ModInt(this) " ~ op ~ "= a"); }
  ModInt opBinaryRight(string op, T)(T a) const { return mixin("ModInt(a) " ~ op ~ "= this"); }
  bool opCast(T: bool)() const { return (x != 0U); }
  string toString() const { return x.to!string; }
}

alias Mint = ModInt;


enum LIM_INV = 4010;
Mint[] inv, fac, invFac;
void prepare() {
  inv = new Mint[LIM_INV];
  fac = new Mint[LIM_INV];
  invFac = new Mint[LIM_INV];
  inv[1] = 1;
  foreach (i; 2 .. LIM_INV) {
    inv[i] = -((Mint.M / i) * inv[cast(size_t)(Mint.M % i)]);
  }
  fac[0] = invFac[0] = 1;
  foreach (i; 1 .. LIM_INV) {
    fac[i] = fac[i - 1] * i;
    invFac[i] = invFac[i - 1] * inv[i];
  }
}
Mint binom(long n, long k) {
  if (n < 0) {
    if (k >= 0) {
      return (-1)^^(k & 1) * binom(-n + k - 1, k);
    } else if (n - k >= 0) {
      return (-1)^^((n - k) & 1) * binom(-k - 1, n - k);
    } else {
      return Mint(0);
    }
  } else {
    if (0 <= k && k <= n) {
      assert(n < LIM_INV);
      return fac[cast(size_t)(n)] * invFac[cast(size_t)(k)] * invFac[cast(size_t)(n - k)];
    } else {
      return Mint(0);
    }
  }
}


int N;
int[] A, B;

int[][] G;
// max <= k
Mint[][] dp;

void dfs(int u, int p) {
  int[] vs;
  foreach (i; G[u]) {
    const v = A[i] ^ B[i] ^ u;
    if (v != p) {
      vs ~= v;
    }
  }
  const len = cast(int)(vs.length);
  foreach (v; vs) {
    dfs(v, u);
  }
  
  auto lss = new Mint[][](len + 1, N);
  auto rss = new Mint[][](len + 1, N);
  lss[0][] = Mint(1);
  foreach (j; 0 .. len) foreach (k; 0 .. N) {
    lss[j + 1][k] = lss[j][k] * dp[vs[j]][k];
  }
  rss[len][] = Mint(1);
  foreach_reverse (j; 0 .. len) foreach (k; 0 .. N) {
    rss[j][k] = dp[vs[j]][k] * rss[j + 1][k];
  }
  
  // max <= here
  foreach (k; 0 .. N) {
    dp[u][k] += rss[0][k];
  }
  
  // 2nd <= here < max
  if (~p) {
    foreach (j; 0 .. len) {
      const v = vs[j];
      Mint sum;
      foreach (k; 0 .. N) {
        dp[u][k] += (k ? (dp[v][k] - dp[v][k - 1]) : dp[v][k]) * sum;
        sum += lss[j][k] * rss[j + 1][k];
      }
    }
    foreach (k; 1 .. N) {
      dp[u][k] += dp[u][k - 1];
    }
  }
  
  debug {
    writeln(u, ": ", dp[u]);
  }
}

void main() {
  try {
    for (; ; ) {
      N = readInt;
      Mint.M = readInt;
      prepare;
      
      A = new int[N - 1];
      B = new int[N - 1];
      foreach (i; 0 .. N - 1) {
        A[i] = readInt - 1;
        B[i] = readInt - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. N - 1) {
        G[A[i]] ~= i;
        G[B[i]] ~= i;
      }
      dp = new Mint[][](N, N);
      dfs(0, -1);
      
      auto ans = dp[0].dup;
      foreach (k; 0 .. N) {
        foreach (l; 0 .. k) {
          ans[k] -= binom(k + 1, l + 1) * ans[l];
        }
      }
      
      foreach (k; 0 .. N - 1) {
        if (k) write(" ");
        write(ans[k]);
      }
      writeln;
    }
  } catch (EOFException e) {
  }
}