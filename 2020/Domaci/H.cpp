/*
 *	Post competition solution to the problem H based on what Kachnicka proposed and what in fact
 *	tourned out to be the organizer's solution.
 * */
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define int long long
#define f(i, a, b) for(int i = (a); a < (b); ++i)

pii make_valid(int x, int y, int r, int c)
{
	if((x >= 0 && x < r) && (y >= 0 && y < c))
		return pii(x, y);
	else
	{
		if(x < 0)
			x = 0;
		if(x == r)
			x = r - 1;
		if(y == c)
			y = 0;
		if(y == -1)
			y = c -1;
	}
	return pii(x, y);
}

bool same_pairs(pii p1, pii p2)
{
	return ((p1.first == p2.first) && (p1.second == p2.second));
}

pii find(pii x, vector<vector<pii>> &parent)
{
	if(same_pairs(x, parent[x.first][x.second]))
		return x;
	pii out = find(parent[x.first][x.second], parent);
	parent[x.first][x.second] = out;
	return out;
}

void uni(pii x, pii y, vector<vector<pii>> &parent, vvi &rank)
{
	int r1, r2;
	r1 = rank[x.first][x.second];
	r2 = rank[y.first][y.second];
	if(r1 > r2)
	{
		pii sec = find(y, parent);
		parent[sec.first][sec.second] = find(x, parent);
		rank[x.first][x.second] += rank[y.first][y.second];
	}
	else
	{
		pii sec = find(x, parent);
		parent[sec.first][sec.second] = find(y, parent);
		rank[y.first][y.second] += rank[x.first][x.second];
	}
}

void solve()
{
	int r, c, n;
	bool thin = false;
	cin >> r >> c >> n;
	//cout << r << " " << c << endl;
	if(c == 1)
		thin = true;
	
	vector<vector<pii>> parent(r, vector<pii>(2*c, pii(-1,-1)));
	vvi rank(r, vi(2*c, 1));
	vector<vector<bool>> desert(r, vector<bool>(2*c, false));
	for( int i = 0; i <r ; ++i)
	{
		for(int j = 0; j < 2*c; ++j)
		{
			//cout << j << endl;
			parent[i][j].first = i;
			parent[i][j].second = j;
		}
	}
	int x, y, out, a, b;
	out = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if(thin)
			continue;
		//cout << x << " " << y <<endl;
		x--; y--;
		if(desert[x][y])
			continue;
		// cout << x << " "<< y << endl;
		vector<pii> n1, n2;
		for(int j = -1; j <= 1; ++j)
			for(int k = -1; k <= 1; ++k)
			{
				pii edge = make_valid(x+j, y+k, r, 2*c);
				if(desert[edge.first][edge.second])
					n1.push_back(find(edge, parent));
				edge = make_valid(x+j, y+k + c, r, 2*c);
				if(desert[edge.first][edge.second])
					n2.push_back(find(edge, parent));
			}
		bool problem = false;
		for(auto car: n1)
		{
			for(auto bus: n2)
			{
				if(same_pairs(car, bus))
				{
					problem = true;
					break;
				}
			}
			if(problem)
				break;
		}
		if(problem)
			out++;
		else
		{
			if(n1.size())
			{
				for(int j = 1; j < n1.size(); ++j)
					uni(n1[0], n1[j],parent, rank);
				uni(pii(x,y),n1[0], parent, rank);
			}
			if(n2.size())
			{
				for(int j = 1; j < n2.size(); ++j)
					uni(n2[0], n2[j],parent, rank);
				uni(pii(x,y + c),n2[0], parent, rank);
			}
			desert[x][y] = true;
			desert[x][y+c] = true;			
		}
	}
	if(thin)
		cout << "0\n";
	else
		cout << n - out << endl;
}

signed main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
		solve();

  return 0;
}

