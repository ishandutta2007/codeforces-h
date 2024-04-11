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


int N;
int[][] graph;

alias Result = Tuple!(int, "d", int, "u");

Result dfs(int u, int p) {
  auto ret = Result(0, u);
  foreach (v; graph[u]) {
    if (v != p) {
      const res = dfs(v, u);
      chmax(ret, Result(1 + res.d, res.u));
    }
  }
  return ret;
}

void main() {
  try {
    for (; ; ) {
      N = readInt();
      const K = readInt();
      
      int[][] ans;
      int n = 1 + (N - 1) % K;
      foreach (u; 1 .. n) {
        ans ~= [0, u];
      }
      int a, b;
      if (n == 1) {
        a = 0;
        b = 1;
      } else if (n == 2) {
        a = 0;
        b = 2;
      } else {
        a = 1;
        b = n;
      }
      debug {
        writefln("N = %s, K = %s", N, K);
        writefln("n = %s, a = %s, b = %s", n, a, b);
      }
      for (; n < N; n += K) {
        foreach (k; 0 .. K) {
          ans ~= [a + k % (b - a), n + k];
        }
        a = n;
        b = n + K;
      }
      
      graph = new int[][N];
      foreach (edge; ans) {
        graph[edge[0]] ~= edge[1];
        graph[edge[1]] ~= edge[0];
      }
      const res0 = dfs(0, -1);
      const res1 = dfs(res0.u, -1);
      writeln(res1.d);
      foreach (edge; ans) {
        writeln(edge[0] + 1, " ", edge[1] + 1);
      }
    }
  } catch (EOFException e) {
  }
}