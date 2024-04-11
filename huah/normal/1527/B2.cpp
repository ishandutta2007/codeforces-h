#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
const int N=3e5+5;
int n;
char s[N];
bool ispd()
{
    for(int i=1;i<=n;i++)
        if(s[i]!=s[n-i+1]) return false;
    return true;
}
int main()
{
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    int t;sc(t);
    while(t--)
    {
        sc(n);
        sc(s+1);
        if(ispd())
        {
            int a=0,b=0;
            if(n&1) b=s[(n+1)/2]=='0';
            for(int i=1;i<=n/2;i++)
                a+=s[i]=='0';
            if(a==0&&b==0) printf("DRAW\n");
            else if(b==0) printf("BOB\n");
            else
            {
                if(a) printf("ALICE\n");
                else printf("BOB\n");
            }
        }
        else
        {
            int a=0,b=0,c=0;
            if(n&1) b=s[(n+1)/2]=='0';
            for(int i=1;i<=n/2;i++)
            {
                a+=s[i]=='0'&&s[n-i+1]=='0';
                c+=s[i]!=s[n-i+1];
            }
            if(a==0&&b==0&&c==0) printf("DRAW\n");
            else if(a==0)
            {
                if(c==1&&b==1) printf("DRAW\n");
                else printf("ALICE\n");
            }
            else printf("ALICE\n");
        }
    }
}