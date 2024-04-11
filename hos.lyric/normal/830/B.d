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


void bAdd(T)(T[] bit, int pos, T val)
in {
  assert(0 <= pos && pos < bit.length, "bAdd: 0 <= pos < |bit| must hold");
}
do {
  for (int x = pos; x < bit.length; x |= x + 1) {
    bit[x] += val;
  }
}

// sum of [0, pos)
T bSum(T)(T[] bit, int pos)
in {
  assert(0 <= pos && pos <= bit.length, "bSum: 0 <= pos <= |bit| must hold");
}
do {
  T ret = 0;
  for (int x = pos - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
}


void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new int[N];
      foreach (i; 0 .. N) {
        A[i] = readInt();
      }
      
      const lim = A.maxElement + 1;
      auto poss = new RedBlackTree!int[lim];
      foreach (a; 0 .. lim) {
        poss[a] = new RedBlackTree!int;
      }
      foreach (i; 0 .. N) {
        poss[A[i]].insert(i);
      }
      
      auto bit = new int[N];
      foreach (i; 0 .. N) {
        bit.bAdd(i, +1);
      }
      
      long ans;
      int cur;
      foreach (a; 0 .. lim) {
        for (; !poss[a].empty; ) {
          auto ran = poss[a].upperBound(cur - 1);
          if (ran.empty) {
            ans += bit.bSum(N) - bit.bSum(cur);
            cur = 0;
            ran = poss[a][];
          }
          const i = ran.front;
          poss[a].removeKey(i);
          ans += bit.bSum(i) - bit.bSum(cur);
          ans += 1;
          bit.bAdd(i, -1);
          cur = i;
          debug {
            writeln("cur = ", cur, ", ans = ", ans);
          }
        }
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}