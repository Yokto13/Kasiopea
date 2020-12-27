/** 
 * This solution is not yet working.
 * Funnuly enough when I used the solution give by organizers, that they claim
 * to be corrected, it started to be very buggy. So indeed there is no working
 * solution to test this one againts.
 * */
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define int long long
#define f(i, a, b) for(int i = (a); a < (b); ++i)
#define PB push_back

vector<bool> globVis;
vi topo;

void reverse(vvi &G,vvi &rev)
{
	rev = vvi(G.size(), vi());
	for(int i = 0; i < G.size(); ++i)
		for(auto v: G[i])
			rev[v].PB(i);
}

void dfs(int v, vvi &G)
{
	globVis[v] = true;
	for(auto u:G[v])
	{
		if(!globVis[u])
			dfs(u, G);
	}
	topo.PB(v);
}

void toposort(vvi &G)
{
	topo = vi();
	globVis = vector<bool>(G.size(), false);
	for(int i = 0; i < G.size(); ++i)
		if(!globVis[i])
			dfs(i, G);
	//reverse(topo.begin(), topo.end());
}

vi tarjan(vi &topo, vvi &G)
{
	int index = 0;
	int n = G.size();
	vi comps(n, -1);
	vi sstack;
	for(auto u: topo)
		sstack.PB(u);
	vector<bool> visited(n, false);
	while(sstack.size())
	{
		vi stack;
		int u = sstack.back();
		stack.PB(u);
		sstack.pop_back();
		while(stack.size())
		{
			u = stack.back();
			stack.pop_back();
			if(visited[u])
				continue;
			for(auto v: G[u])
				stack.PB(v);
			visited[u] = true;
			comps[u] = index;
		}
		index++;
	}
	return comps;
}


int solve(vvi &G)
{
	int n = G.size();
	vvi rev;
	reverse(G, rev);
	toposort(rev);
	vi comps = tarjan(topo, G);
	vector<bool> visited(n, false);
	int out = 0;
	vi sizes(n, 0);
	for(auto c: comps)
		sizes[c]++;

	reverse(topo.begin(), topo.end());
	for(int i = topo.size(); i >= 0; i--)
	{
		if(!visited[topo[i]])
		{
			set<int> s;
			vi stack;
			stack.PB(topo[i]);
			while(stack.size())
			{
				int u = stack.back();
				stack.pop_back();
				if(visited[u])
					continue;
				for(auto v: G[u])
					stack.PB(v);
				visited[u] = true;
				s.insert(comps[u]);
			}
			int all = 0;
			for(auto i: s)
				all+= sizes[i];
			out = max(out, all);
		}
	}
	return out;
}

signed main()
{
	int t, n, m, a, b;
	cin >> t;
	vi out;
	for(int i = 0; i < t;++i)
	{
		cin >> n >> m;
		vvi G(n, vi());
		for(int j = 0; j < m; ++j)
		{
			cin >> a >> b;
			a--; b--;
			G[a].PB(b);
		}
		out.push_back(solve(G));
	}
	for(int i = 0; i < t; ++i)
		cout << out[i] << "\n";
  return 0;
}

