#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
int main(){
    char c[105];
    scanf("%s",c);
    for(int i=1;c[i+1]!=0;i++){
        int ans=0;
        for(int j=i-1;j<=i+1;j++){
            if(c[j]!='.')
            ans+=1<<(c[j]-'A');
        }
        if(ans==7){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}