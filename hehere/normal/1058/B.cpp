#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using U = unsigned int;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using std::cin; using std::cout;
using std::endl; using std::cerr;
using std::bitset; using std::map;
using std::queue; using std::priority_queue;
using std::set; using std::string;
using std::vector;
using std::pair; using std::make_pair;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;
#ifdef LOCAL
#include <ctime>
void displayTime() { cout << "Current time = " << clock() * 1e3 / CLOCKS_PER_SEC << "ms" << endl; }
#else
void displayTime() {}
#endif
#ifdef DEBUG
#define pass cerr << "[" << __FUNCTION__ << "] : line = " << __LINE__ << endl;
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n) { cerr << #a << " = {"; \
      for(int qwq = (st); qwq <= (n); ++qwq) cerr << a[qwq] << (qwq == n ? '}' : ',') << (qwq == n ? '\n' : ' '); }
#include <ctime>
class MyTimer {
  clock_t st;
public:
  MyTimer() { cerr << std::fixed << std::setprecision(0); reset(); }
  ~MyTimer() { report(); }
  void reset() { st = clock_t(); }
  void report() {  cerr << "Time consumed :" << (clock() - st) * 1e3 / CLOCKS_PER_SEC << endl; }
} myTimer;
#else
#define pass ;
#define display(x) ;
#define displaya(a, st, n) {}
class MyTimer {
public: void reset() {} void report() {}
} myTimer;
#endif

template<typename T1, typename T2>
inline bool chmin(T1 &a, const T2 &b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
inline bool chmax(T1 &a, const T2 &b) { return a < b ? a = b, true : false; }
#ifdef QUICK_READ
char pool[1<<15|1],*it=pool+32768;
#define getchar() (it>=pool+32768?(pool[fread(pool,sizeof(char),1<<15,stdin)]=EOF,*((it=pool)++)):*(it++))
#endif
inline int readint() {
  int a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}
inline LL readLL() {
  LL a = 0; char c = getchar(), p = 0;
  while(isspace(c)) c = getchar();
  if(c == '-') p = 1, c = getchar();
  while(isdigit(c)) a = a*10 + c - '0', c = getchar();
  return p ? -a : a;
}

const int maxM = 100 + 5;
int n, d, m;

int check() {
  int x, y; cin >> x >> y;
  if(y >= d - x && y - n <= n - d - x && y <= x + d && y >= x - d) return 1;
  return 0;
}

int main() {
  cin >> n >> d >> m;
  for(int i = 1; i <= m; ++i) if(check()) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}