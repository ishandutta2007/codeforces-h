#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    string s2=s;
    sort(s2.begin(),s2.end());
    int ans=0;
    for(int i = 0;i<n;i++){
        if(s[i]!=s2[i])ans++;
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
0 1 1 1
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
x^2+y^2=kxy+k;
64+y^2=32y+4;
y^2-32y+60=0;

x^2-k*y*x-k+y*y=0;
a=1;
b=-k*y;
c=y*y-k
x=ky+-sqrt(k*k*y*y+4*k-4*y*y) 
*/