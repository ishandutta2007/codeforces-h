#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
int main()
{
    int T; cin>>T;
    while(T--){
        int n;
        scanf("%d", &n);
        fors(i,1,n+1){
            printf("2");
            if(i == n) cout<<endl;
            else cout<<" ";
        }
    }
}