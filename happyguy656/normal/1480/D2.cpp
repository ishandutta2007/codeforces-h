#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3;
int a[mxn],n,nxt[mxn],pos[mxn];

int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=0;i<=n;++i)pos[i]=n+1;
    for(int i=n;i;--i)nxt[i]=pos[a[i]],pos[a[i]]=i;
    int x=0,y=0,ans=0,nx=n+1,ny=n+1;
    for(int l=1,r;l<=n;l=r+1){
        r=l;while(r!=n&&a[r+1]==a[l])++r;
        if(a[l]!=x&&a[l]!=y){
            ++ans;
            if(nx<ny)y=a[l],ny=nxt[r];
            else x=a[l],nx=nxt[r];
        }else{
            if(a[l]==x)nx=nxt[r];
            if(a[l]==y)ny=nxt[r];
        }
    }
    
    printf("%d\n",ans);
    return 0;
}