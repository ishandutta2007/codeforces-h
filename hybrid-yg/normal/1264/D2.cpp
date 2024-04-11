#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
char s[1000005];
int a,b,c,d,i,j;
long long fac[1000005],inv[1000005],ans;
long long C(long long n,long long m)
{
	if(n<0||m<0||n<m)
		return 0;
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
int main()
{
	scanf("%s",s+1);
	for(i=1;s[i];++i)
	{
		if(s[i]=='?')
			++b;
		if(s[i]==')')
			++d;
	}
	inv[0]=inv[1]=fac[0]=1;
	for(i=2;i<=1000000;++i)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(i=1;i<=1000000;++i)
	{
		fac[i]=fac[i-1]*i%M;
		inv[i]=inv[i-1]*inv[i]%M;
	}
	for(i=1;s[i];++i)
	{
		if(s[i]=='?')
			++a,--b;
		if(s[i]=='(')
			++c;
		if(s[i]==')')
			--d;
		ans=(ans+C(a+b,b-c+d)*(b+d)-C(a+b-1,b-c+d-1)*b)%M;
	}
	cout<<(ans%M+M)%M;
}