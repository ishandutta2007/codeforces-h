#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];

		if(!a[i])
			i-- , n--;
	}

	sort(a , a + n);
	n = unique(a , a + n) - a;
	cout << n << endl;
	
}