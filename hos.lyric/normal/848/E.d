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

struct ModInt(int M_) {
  import std.conv : to;
  alias M = M_;
  int x;
  this(ModInt a) { x = a.x; }
  this(long a) { x = cast(int)(a % M); if (x < 0) x += M; }
  ref ModInt opAssign(long a) { return (this = ModInt(a)); }
  ref ModInt opOpAssign(string op)(ModInt a) {
    static if (op == "+") { x += a.x; if (x >= M) x -= M; }
    else static if (op == "-") { x -= a.x; if (x < 0) x += M; }
    else static if (op == "*") { x = cast(int)((cast(long)(x) * a.x) % M); }
    else static if (op == "/") { this *= a.inv(); }
    else static assert(false);
    return this;
  }
  ref ModInt opOpAssign(string op)(long a) {
    static if (op == "^^") {
      if (a < 0) return (this = inv()^^(-a));
      ModInt t2 = this, te = ModInt(1);
      for (long e = a; e > 0; e >>= 1) {
        if (e & 1) te *= t2;
        t2 *= t2;
      }
      x = cast(int)(te.x);
      return this;
    } else return mixin("this " ~ op ~ "= ModInt(a)");
  }
  ModInt inv() const {
    int a = x, b = M, y = 1, z = 0, t;
    for (; ; ) {
      t = a / b; a -= t * b;
      if (a == 0) {
        assert(b == 1 || b == -1);
        return ModInt(b * z);
      }
      y -= t * z;
      t = b / a; b -= t * a;
      if (b == 0) {
        assert(a == 1 || a == -1);
        return ModInt(a * y);
      }
      z -= t * y;
    }
  }
  ModInt opUnary(string op: "-")() const { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const {
    return mixin("ModInt(this) " ~ op ~ "= a");
  }
  ModInt opBinaryRight(string op)(long a) const {
    return mixin("ModInt(a) " ~ op ~ "= this");
  }
  bool opCast(T: bool)() const { return (x != 0); }
  string toString() const { return x.to!string; }
}

enum MO = 998244353;
alias Mint = ModInt!MO;


// Pretty print (smaller abs)
int[] pretty(int M)(ModInt!M[] as) {
  import std.algorithm : map;
  import std.array : array;
  return as.map!(a => (a.x < M - a.x) ? a.x : -(M - a.x)).array;
}

// Berlekamp-Massey
//   F: field
//   \sum_{j=1}^0 cs[j] as[i - j] = 0 (d <= i < |as|), cs[0] = 1
//   M must be prime
F[] findLinearRecurrence(F)(F[] as) {
  import std.algorithm : min;
  const n = cast(int)(as.length);
  int d, m;
  auto cs = new F[n + 1], bs = new F[n + 1];
  cs[0] = bs[0] = 1;
  F invBef = 1;
  foreach (i; 0 .. n) {
    ++m;
    F dif = as[i];
    foreach (j; 1 .. d + 1) dif += cs[j] * as[i - j];
    if (dif.x != 0) {
      auto csDup = cs.dup;
      const r = dif * invBef;
      foreach (j; m .. n) cs[j] -= r * bs[j - m];
      if (2 * d <= i) {
        d = i + 1 - d;
        m = 0;
        bs = csDup;
        invBef = dif.inv;
      }
    }
  }
  return cs[0 .. d + 1];
}


enum LIM_N = 50005;
enum LIM_SMALL = 100;

void main() {
  auto pat = new Mint[LIM_SMALL];
  pat[0] = pat[1] = 1;
  foreach (i; 2 .. LIM_SMALL) {
    pat[i] = pat[i - 1] + pat[i - 2];
  }
  auto as = new Mint[LIM_SMALL];
  foreach (n; 3 .. LIM_SMALL) {
    auto dp = new Mint[][][](n + 1, 2, 2);
    foreach (s; 0 .. 2) {
      dp[0][s][s] = 1;
    }
    foreach (i; 0 .. n) {
      foreach (s; 0 .. 2) foreach (t; 0 .. 2) {
        foreach (j; i + 1 .. n + 1) {
          foreach (u; 0 .. 2) {
            if (j - i - 1 - t - u >= 0 && (j - i - 1 - t - u) % 2 == 0) {
              Mint tmp = dp[i][s][t];
              if (i == 0) {
                tmp *= (j - i);
              }
              tmp *= pat[(j - i - 1 - t - u) / 2];
              tmp *= (j - i - 1)^^2;
              dp[j][s][u] += tmp;
            }
          }
        }
      }
    }
    foreach (s; 0 .. 2) {
      as[n] += dp[n][s][s];
    }
  }
  auto cs = as.findLinearRecurrence;
  debug {
    writeln("as = ", as);
    writeln("cs = ", cs.pretty);
  }
  const d = cast(int)(cs.length) - 1;
  as.length = LIM_N;
  foreach (i; LIM_SMALL .. LIM_N) {
    foreach (j; 1 .. d + 1) {
      as[i] -= cs[j] * as[i - j];
    }
  }
  
  try {
    for (; ; ) {
      const N = readInt();
      writeln(as[N]);
    }
  } catch (EOFException e) {
  }
}