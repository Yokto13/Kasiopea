#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define int long long
#define f(i, a, b) for(int i = (a); a < (b); ++i)

signed main()
{
	int t, n, x, c, b, bi;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		cin >> n;
		vi stones(n+1, 10000000);
		stones[0] = 0;
		c = 0;
		for(int j = 0; j < n; ++j)
		{
			cin >> stones[j];
		}
		for(int j = 0; j <= n;)
		{
			b = 0;
			bi = -1;
			int k = j + 1;
			for(; k <= min(stones[j] + j, n); k++)
			{
				if(stones[k] + k - j - 1 > b)
				{
				//	cout << k+1 << endl;
					b = stones[k] + k - j - 1;
					bi = k;
				}
			}
			//cout << "------------\n";
			c++;
			j = bi;
			if(j + stones[j] >= n)
				break;
		}
		cout << c + 1 << endl;
		//cout << "************\n";
	}
  return 0;
}

