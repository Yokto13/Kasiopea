#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define int long long
#define f(i, a, b) for(int i = (a); a < (b); ++i)

bool solve()
{
	int n, m, k, x, y;
	cin >> n >> m >> k;
	vi people(n, 0);
	for(int i = 0; i < n; ++i)
		cin >> people[i];
	vvi G(n, vi());
	for(int i = 0; i < m ; ++i)
	{
		cin >> x >> y;
		x--; y--;
		if(people[y] >= people[x])
			G[x].push_back(people[y]);
		if(people[x] >= people[y])
			G[y].push_back(people[x]);
	}
	for(int i = 0; i < n ; ++i)
		sort(G[i].begin(), G[i].end());
	for(int i = 0; i < n; ++i)
	{
		if(!G[i].size())
		{
			if(people[i] < k)
				return true;
			continue;
		}
		// cout << "f\n";
		if(G[i][G[i].size() - 1] < k)
			return true;
		// cout << "s\n";
		for(int j = 0; j < G[i].size() - 1; ++j)
			if((G[i][j+1] - G[i][j]) > 1)
				return true;
	}
	return false;
}

signed main()
{
	int t;
	cin >> t;
	for(int _ = 0; _ < t; ++_)
	{
		if(solve())
			cout << "ANO\n";
		else
			cout << "NE\n";
	}

  return 0;
}

