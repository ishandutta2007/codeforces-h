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
#define hash Hash;
#define MXN 100005
//#define assert(x) while(!(x))
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[200005];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    int Max=n+1,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        LL tot=0;
        int cnt=0;
        int index=0;
        while(index!=n){
            for(int i=0;i<mid;i++){
                tot+=max(a[index++]-cnt,0);
                if(index==n)
                break;
            }
            cnt++;
        }
        if(tot>=m)
            Max=mid;
        else 
            Min=mid;
    }
    if(Max==n+1)Max=-1;
    printf("%d\n",Max);
}