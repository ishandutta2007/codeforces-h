#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
//mt19937 rnd(time(0));
//int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

int n,a[103];

void sol(){
    cin>>n;for(int i=1;i<=n;++i)cin>>a[i];
    ll s=0;for(int i=1;i<=n;++i)s+=a[i];
    if(s%n)puts("1");else puts("0");
}

int main(){
    int ca;cin>>ca;while(ca--)sol();
    return 0;
}