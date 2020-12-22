#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define int long long
#define f(i, a, b) for(int i = (a); a < (b); ++i)

signed main()
{
	int t, n, m, x;
	cin >> t;
	for(int _ = 0; _ < t; ++_)
	{
		cin >> n >> m;
		vi res(m, 0);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				cin >> x;
				res[j] = res[j] ^ x;
			}
		}
		for(int i = 0; i < m; ++i)
			cout << res[i] << " ";
		cout << endl;
	}
  return 0;
}

