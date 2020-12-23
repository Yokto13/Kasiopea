/**
 * If run on a good hardware with -Ofast and -march=native, 
 * this naive solution gives the result in time.
 * 
 * Alternatively, it might also be parallelized. 
 * In such a case it should be quick enough pretty much anywhere.
 *
 * It is also possible to solve this problem with O(N^3) solution, with 
 * good enough optimalization, multithreading and good computer. However,
 * it's gonna be tight.
 * */

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define int long long
#define f(i, a, b) for(int i = (a); a < (b); ++i)

int solve(int k, vi &days)
{
	vi prefixes;
	int n = days.size();
	prefixes.push_back(0);
	int s = 0;
	for(auto d : days)
	{
		s+= d;
		prefixes.push_back(s);
	}
	int out = 0;
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j <= n; ++j)
			if(prefixes[j] - prefixes[i] < k)
				out++;
	return out;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	int t, n, k;
	cin >> t;
	vvi data(t, vi());
	vi ks;
	for(int i = 0; i < t;++i)
	{
		cin >> n >> k;
		ks.push_back(k);
		data[i] = vi(n, 0);
		for(int j = 0; j < n; ++j)
			cin>> data[i][j];
	}
	vi out;
	for(int i = 0; i < t; ++i)
		out.push_back(solve(ks[i], data[i]));
	for(int i = 0; i < t; ++i)
		cout << out[i] << endl;

  return 0;
}

