#include <stdio.h>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int min = x[1];
	for(int i=2;i<=a;i++) min = min<x[i]?min:x[i];
	
	int ans = 12345678;
	int prev = -12345678;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==min)
		{
			ans = ans<i-prev?ans:i-prev;
			prev = i;
		}
	}
	printf("%d",ans);
}