#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define int long long
#define f(i, a, b) for(int i = (a); a < (b); ++i)

signed main()
{
	int t, x, n, m;
	bool problematic;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		x = 1;
		cin >>n;
		problematic = false;
		for(int j = 0; j < n; ++j)
		{
			cin >> m;
			if((m != x) && (m != 0))
			{
				problematic = true;
			}
			x++;
		}
		if(!problematic)
			cout << "ANO\n";
		else
			cout << "NE\n";
	}
  return 0;
}

