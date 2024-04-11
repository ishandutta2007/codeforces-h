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


enum INF = 10L^^9;
alias City = Tuple!(long, "pos", long, "val");

void main() {
  try {
    for (; ; ) {
      const N = readInt();
      auto A = new City[N];
      foreach (u; 0 .. N) {
        A[u].pos = readLong();
        A[u].val = readLong();
      }
      A.sort;
      debug {
        writeln("A = ", A);
      }
      
      alias Entry = Tuple!(long, "c", int, "u");
      BinaryHeap!(Array!Entry, "a.c > b.c") que;
      auto dist = new long[N];
      dist[] = INF;
      dist[0] = 0;
      que.insert(Entry(0, 0));
      for (; !que.empty; ) {
        const c = que.front.c;
        const u = que.front.u;
        que.removeFront;
        if (dist[u] == c) {
          if (u - 1 >= 0) {
            if (chmin(dist[u - 1], c)) {
              que.insert(Entry(c, u - 1));
            }
          }
          const v = A.lowerBound(City(A[u].pos + A[u].val + 1, -1));
          debug {
            writefln("%s -> %s", u, v);
          }
          if (v - 1 >= 0) {
            if (chmin(dist[v - 1], c)) {
              que.insert(Entry(c, v - 1));
            }
          }
          if (v < N) {
            const cc = c + ((A[v].pos - A[u].pos) - A[u].val);
            if (chmin(dist[v], cc)) {
              que.insert(Entry(cc, v));
            }
          }
        }
      }
      
      long ans = dist[N - 1];
      foreach (u; 0 .. N) {
        ans += A[u].val;
      }
      writeln(ans);
    }
  } catch (EOFException e) {
  }
}