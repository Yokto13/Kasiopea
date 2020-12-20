#include<bits/stdc++.h>

using namespace std;


void solve()
{
    int n;
    cin >> n;
    vector<int> v(n,0);
    vector<int> k(n+2,0);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    k[2] = v[0];
    k[3] = v[1] + v[0];
    for(int i = 4; i < n+2; ++i)
    {
        k[i] = min(k[i-1], k[i-2]) + v[i-2];
    }
    cout << min(k[k.size()-1], k[k.size()-2]) << endl;    
}

int main()
{
    int t;
    cin >> t;
    for(int _ = 0; _ < t; ++_)
    {
        solve();
    }

    return 0;
}
