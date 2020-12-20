#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,m, x1, x2, v;
    bool ruler = true;
    cin  >> t;
    for(int z =0; z < t; ++z)
    {
        ruler = true;
        vector<vector<int>> g;
        cin >> n >> m; 
        for(int i = 0; i < n ;++i)
            g.push_back(vector<int>());
        for(int i = 0; i < m;++i)
        {
            cin >> x1 >> x2;
            x1--;
            x2--;
            g[x1].push_back(x2);
            g[x2].push_back(x1);
        }

        vector<int> s;
        set<int> p;
        vector<bool> dis(n,false);
        vector<bool> rul(n,false);
        for(int sv=0; sv<n;++sv)
        {
            if(!dis[sv])
            {
                s.push_back(sv);
                while(s.size()>0)
                {
                    v = s[s.size()-1];
                    s.pop_back();
                    if(!dis[v])
                    {
                        dis[v] = dis[v]^1;
                        for(int u : g[v])
                        {
                            s.push_back(u);
                            if(!rul[v])
                            {
                                rul[u] = true;
                                p.insert(u+1);   
                            }
                        }
                    }
                }
            }
        }
       // cout << "ruler " << ruler << endl;
       // cout<<g.size();
        for(auto zzz: g)
        {
            if(zzz.size()==0)
            {
               // cout << "hello";
                ruler = false;
                break;
            }
        }
     //   cout << "ruler" << ruler << endl;
        if(ruler)
        {
            cout << "ANO" << endl;
            cout << p.size() << endl;
            for(int u : p)
                cout << u << endl;
        }
        else
        {
            cout << "NE" << endl;
        }
    }

    return 0;
}
