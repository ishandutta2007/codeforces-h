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
      const numCases = readInt();
      foreach (caseId; 0 .. numCases) {
        const M = readInt();
        const N = readInt();
        
        auto ans = new char[][](M, N);
        foreach (x; 0 .. M) {
          ans[x][] = '0';
        }
        ans[0][0] = ans[0][N - 1] = ans[M - 1][0] = ans[M - 1][N - 1] = '1';
        for (int y = 2; y < N - 2; y += 2) {
          ans[0][y] = ans[M - 1][y] = '1';
        }
        for (int x = 2; x < M - 2; x += 2) {
          ans[x][0] = ans[x][N - 1] = '1';
        }
        
        foreach (x; 0 .. M) {
          writeln(ans[x]);
        }
        writeln;
      }
    }
  } catch (EOFException e) {
  }
}