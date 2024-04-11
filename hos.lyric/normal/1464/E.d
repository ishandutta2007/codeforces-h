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


int N, M;
int[] A, B;

int[][] G;
int[] dp;

int calc(int u) {
  if (dp[u] == -1) {
    int[] app;
    foreach (i; G[u]) {
      const v = A[i] ^ B[i] ^ u;
      app ~= calc(v);
    }
    app = app.sort.uniq.array;
    app ~= -1;
    for (int g = 0; ; ++g) {
      if (app[g] != g) {
        dp[u] = g;
        break;
      }
    }
  }
  return dp[u];
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      M = readInt();
      A = new int[M];
      B = new int[M];
      foreach (i; 0 .. M) {
        A[i] = readInt() - 1;
        B[i] = readInt() - 1;
      }
      
      G = new int[][N];
      foreach (i; 0 .. M) {
        G[A[i]] ~= i;
      }
      dp = new int[N];
      dp[] = -1;
      foreach (u; 0 .. N) {
        calc(u);
      }
      debug {
        writeln("dp = ", dp);
      }
      
      const K = bsr(dp.maxElement + 1) + 1;
      auto fs = new Mint[1 << K];
      foreach (u; 0 .. N) {
        fs[dp[u]] += 1;
      }
      fs[] *= (Mint(N + 1).inv);
      foreach (i; 0 .. K) {
        foreach (p; 0 .. 1 << K) {
          if (!(p & 1 << i)) {
            const pp = p | 1 << i;
            const t = fs[p] - fs[pp];
            fs[p] += fs[pp];
            fs[pp] = t;
          }
        }
      }
      foreach (p; 0 .. 1 << K) {
        fs[p] = 1 / (1 - fs[p]);
      }
      foreach (i; 0 .. K) {
        foreach (p; 0 .. 1 << K) {
          if (!(p & 1 << i)) {
            const pp = p | 1 << i;
            const t = fs[p] - fs[pp];
            fs[p] += fs[pp];
            fs[pp] = t;
          }
        }
      }
      fs[] *= Mint(1 << K).inv;
      
      Mint ans = fs[0];
      ans /= Mint(N + 1);
      ans = 1 - ans;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}