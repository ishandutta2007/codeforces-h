#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int c=0,d=0,a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        c += a < 0;
        d += a > 0;
    }
    if (c >= (n+1)/2) cout << -1;
    else if (d >= (n+1)/2) cout << 1;
    else cout << 0;
    
}
/*
{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}









(())(())(())(())(())(())(())(())(())(())(())(())(())(())(())(())(())

 \||/     \||/    \?+==-=-==      |+==|       |+==|       \\=   =//
  |/ |!|!| \|      ?|/       |    ||          ||          |\\+=+//|
  ||   +   ||   |  |/   |    ++=  || )&^@!    || $@^(~    / \\=// \
  +|==???==|+  =+  |++==+=-|      |+   %      |+   *     |  =+X+=  |
  ||   +   ||   |  |\   |    ++=  || ]&"*~    || %'&}!    \ //=\\ /
  |\ |!|!| /|      ?|\       |    ||          ||          |//+=+\\|
 /||\     /||\    /?+==-=-==      |+==+==+=|  |+==+==+=|  //=   =\\

>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<









[[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]]
*/