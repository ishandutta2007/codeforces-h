#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i += 1){
            for(int j = 0, a; j < m; j += 1){
                cin >> a;
                if((a ^ i ^ j) & 1) a += 1;
                cout << a << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}