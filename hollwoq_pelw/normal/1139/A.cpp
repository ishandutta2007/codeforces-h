#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    long long res = 0;
    for (int i = 0; i < n; i++){
        if ((s[i]-'0')%2==0) res += i+1;
    }
    cout << res;
    return 0;
}