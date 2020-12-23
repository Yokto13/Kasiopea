#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define int long long
#define f(i, a, b) for(int i = (a); a < (b); ++i)


void solve()
{
	int n, a, b, q;
	cin >> n;
	vector<pii> mountains;
	vector<pii> stack;	
	map<int, int> ma;
	vi out(n, 10000000000);
	for(int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		mountains.push_back(pii(a,b));
		while(stack.size() && stack.back().second < b)
			stack.pop_back();
		if(stack.size())
		{
			q = stack.back().second + stack.back().first;
			out[i] = abs(q - b - a);
		}
		stack.push_back(pii(a, b));
	}
	while(stack.size())
		stack.pop_back();
	for(int i = n-1; i >= 0; --i)
	{
		a = mountains[i].first;
		b = mountains[i].second;
		while(stack.size() && stack.back().second < b)
			stack.pop_back();
		if(stack.size())
		{
			q = stack.back().second - stack.back().first;
			out[i] = min(abs(b - q - a), out[i]);
		}
		stack.push_back(pii(a, b));
	}


	for(auto bus: out)
	{
		if(bus == 10000000000)
			cout << "-1 ";
		else
			cout << bus << " ";
	}
	cout <<endl;
}

signed main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		solve();
	}
  return 0;
}

