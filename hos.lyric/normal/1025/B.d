import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.numeric, std.regex, std.typecons;
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




void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new long[N];
      auto B = new long[N];
      foreach (i; 0 .. N) {
        A[i] = readLong();
        B[i] = readLong();
      }
      
      long g = 0;
      foreach (i; 0 .. N) {
        const l = A[i] / gcd(A[i], B[i]) * B[i];
        g = gcd(g, l);
      }
      if (g == 1) {
        writeln(-1);
      } else {
        long ans;
        foreach (a; [A[0], B[0]]) {
          const m = gcd(g, a);
          for (long p = 2; p * p <= m; ++p) {
            if (m % p == 0) {
              ans = p;
              goto found;
            }
          }
          if (m > 1) {
            ans = m;
            goto found;
          }
        }
        assert(false);
       found:
        writeln(ans);
      }
    }
  } catch (EOFException e) {
  }
}