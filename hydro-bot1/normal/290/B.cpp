// Hydro submission #6253cf6c48f7830132792694@1649659756999
#include<bits/stdc++.h>
using namespace std;
long long x,y,a[]={
	8545356415,4362120257,6255293533,
	6264519261,6267107677,4384465217,
	8545195391,33017600,4690329081,
	7415415340,3879898762,4039633667,
	8589701720,7565059748,5710113410,
	5916654080,342265690,5535926926,
	6172066696,320013954,1832330456,
	3947133606,7865276942,6615960568,
	1198566896,30098710,8541146458,
	4377475355,6260543992,6248017882,
	6250425712,4375509472,8550259601
};
int main()
{
	cin>>x>>y;
	printf("%d\n",(a[x]>>(32-y)&1));
	return 0;
}