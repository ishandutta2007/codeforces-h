#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, l, r;
    for(cin >> t; t; t -= 1){
        cin >> l >> r;
        if(l * 2 <= r) cout << l << " " << l * 2 << "\n";
        else cout << "-1 -1\n";
    }
    return 0;
}