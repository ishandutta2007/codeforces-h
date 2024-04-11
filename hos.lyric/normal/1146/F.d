import std.conv, std.functional, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.complex, std.container, std.math, std.numeric, std.range, std.regex, std.typecons;
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


enum long MO = 998244353;

int N;
int[] P;

void main() {
  try {
    for (; ; ) {
      N = readInt();
      P = new int[N];
      P[0] = -1;
      foreach (u; 1 .. N) {
        P[u] = readInt() - 1;
      }
      
      auto graph = new int[][N];
      foreach (u; 1 .. N) {
        graph[P[u]] ~= u;
      }
      
      auto dp = new long[][](N, 3);
      foreach_reverse (u; 0 .. N) {
        if (graph[u].empty) {
          dp[u] = [0, 0, 1];
        } else {
          auto crt = new long[3];
          crt[0] = 1;
          foreach (v; graph[u]) {
            auto nxt = new long[3];
            foreach (x; 0 .. 3) foreach (y; 0 .. 3) {
              if (y != 1) {
                nxt[x] += crt[x] * dp[v][y];
                nxt[x] %= MO;
              }
              if (y != 0) {
                nxt[min(x + 1, 2)] += crt[x] * dp[v][y];
                nxt[min(x + 1, 2)] %= MO;
              }
            }
            crt = nxt;
          }
          dp[u] = crt;
        }
      }
      debug {
        writeln("dp = ", dp);
      }
      long ans = (dp[0][0] + dp[0][2]) % MO;
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}