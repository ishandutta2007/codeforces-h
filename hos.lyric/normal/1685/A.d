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




void main() {
  try {
    for (; ; ) {
      const numCases = readInt;
      foreach (caseId; 0 .. numCases) {
        const N = readInt;
        auto A = new int[N];
        foreach (i; 0 .. N) {
          A[i] = readInt;
        }
        A.sort;
        
        int[] ans;
        if (N % 2 == 0) {
          foreach (i; 0 .. N / 2) {
            ans ~= A[i];
            ans ~= A[i + N / 2];
          }
          debug {
            writeln(ans);
          }
          bool ok = true;
          foreach (i; 0 .. N) {
            const a0 = ans[i];
            const a1 = ans[(i + 1 == N) ? 0 : (i + 1)];
            ok = ok && ((i % 2 == 0) ? (a0 < a1) : (a0 > a1));
          }
          if (!ok) {
            ans = null;
          }
        }
        
        if (ans) {
          writeln("YES");
          foreach (i; 0 .. N) {
            if (i) write(" ");
            write(ans[i]);
          }
          writeln;
        } else {
          writeln("NO");
        }
      }
    }
  } catch (EOFException e) {
  }
}