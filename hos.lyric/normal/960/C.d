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
      const X = readLong();
      const D = readLong();
      
      int[] es;
      for (long x = X; x > 0; ) {
        // 2^e - 1 <= x
        const e = bsr(x + 1);
        es ~= e;
        x -= ((1L << e) - 1);
      }
      debug {
        writeln("es = ", es);
      }
      
      long[] ans;
      long val = 1;
      foreach (e; es) {
        ans ~= repeat(val, e).array;
        val += D;
      }
      writeln(ans.length);
      foreach (i, a; ans) {
        if (i > 0) write(" ");
        write(a);
      }
      writeln();
    }
  } catch (EOFException e) {
  }
}