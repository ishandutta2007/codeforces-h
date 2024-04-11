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
      ModInt t2 = this, te = ModInt(1);
      for (long e = a; e; e >>= 1) {
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
  ModInt opUnary(string op)() const if (op == "-") { return ModInt(-x); }
  ModInt opBinary(string op, T)(T a) const { return mixin("ModInt(this) " ~ op ~ "= a"); }
  ModInt opBinaryRight(string op)(long a) const { return mixin("ModInt(a) " ~ op ~ "= this"); }
  string toString() const { return x.to!string; }
}

enum MO = 998244353;
alias Mint = ModInt!MO;

// 1 + p0 + p0 p1 + p0 p1 p2
struct Info {
  Mint prod, sum;
  Info opBinary(string op)(Info a) const if (op == "*") {
    return Info(prod * a.prod, sum + prod * a.sum);
  }
}
enum IDENTITY = Info(Mint(1), Mint(0));

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      const Q = readInt();
      auto P = new int[N];
      foreach (i; 0 .. N) {
        P[i] = readInt();
      }
      auto U = new int[Q];
      foreach (q; 0 .. Q) {
        U[q] = readInt() - 1;
      }
      
      int segN;
      for (segN = 1; segN < N; segN <<= 1) {}
      auto seg = new Info[segN << 1];
      seg[] = IDENTITY;
      foreach (i; 0 .. N) {
        seg[segN + i] = Info(Mint(P[i]) / 100, Mint(1));
      }
      foreach_reverse (a; 1 .. segN) {
        seg[a] = seg[a << 1] * seg[a << 1 | 1];
      }
      Info rangeProd(int a, int b) {
        Info retL = IDENTITY, retR = IDENTITY;
        for (a += segN, b += segN; a < b; a >>= 1, b >>= 1) {
          if (a & 1) retL = retL * seg[a++];
          if (b & 1) retR = seg[--b] * retR;
        }
        return retL * retR;
      }
      Mint calc(int a, int b) {
        const res = rangeProd(a, b);
        const ret = res.sum / res.prod;
        debug {
          writeln("calc ", a, " ", b, ": ", res, " ", ret);
        }
        return ret;
      }
      
      auto set = new RedBlackTree!int;
      set.insert(0);
      set.insert(N);
      Mint now = calc(0, N);
      foreach (q; 0 .. Q) {
        const l = set.lowerBound(U[q]).back;
        const r = set.upperBound(U[q]).front;
        if (set.removeKey(U[q])) {
          debug {
            writeln("remove ", U[q], "; ", l, " ", r);
          }
          now -= calc(l, U[q]);
          now -= calc(U[q], r);
          now += calc(l, r);
        } else {
          debug {
            writeln("insert ", U[q], "; ", l, " ", r);
          }
          set.insert(U[q]);
          now -= calc(l, r);
          now += calc(l, U[q]);
          now += calc(U[q], r);
        }
        writeln(now);
      }
    }
  } catch (EOFException e) {
  }
}