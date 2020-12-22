#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define int long long
#define f(i, a, b) for(int i = (a); a < (b); ++i)

signed main()
{
	int t, n, x;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		cin >> n;
		vi stones(n+1, 10000000);
		stones[0] = 0;
		for(int j = 0; j < n; ++j)
		{
			cin >> x;
			for(int k = j+1; k <= min(j + x, n); ++k)
				stones[k] = min(stones[k], stones[j] + 1);
		}
		cout << stones[n] << endl;
	}
  return 0;
}

