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
long[] A;

long Ask(int i) {
  debug {
    return A[i];
  } else {
    writefln("? %s", i + 1);
    stdout.flush;
    const res = readLong();
    return res;
  }
}
void Answer(int i) {
  writefln("! %s", i + 1);
  stdout.flush;
  import core.stdc.stdlib;
  exit(0);
}

void main() {
  N = readInt();
  debug {
    A = new long[N];
    foreach (i; 0 .. N) {
      A[i] = readInt();
    }
  }
  
  if (N % 4 != 0) {
    Answer(-2);
  }
  
  const a = Ask(0);
  const b = Ask(N / 2);
  if (a == b) {
    Answer(0);
  }
  int lo = 0, hi = N / 2;
  for (; lo + 1 < hi; ) {
    const mid = (lo + hi) / 2;
    const c = Ask(mid);
    const d = Ask(mid + N / 2);
    if (c == d) {
      Answer(mid);
    }
    (((a < b) == (c < d)) ? lo : hi) = mid;
  }
  Answer(hi);
}