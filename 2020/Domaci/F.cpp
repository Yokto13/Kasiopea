// Suprisingly working solution.
// Works only on a decent hardware with processor specific
// optimalization.
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(0);
    int t, n, x;
    cin >> t;
    for(int _ = 0; _ < t; ++_)
    {
        cin >> n;
        //cout << n << endl;
        vector<int> data(n, -1);
        vector<bool> visited(n, false);
        bool good = false;
        for(int i = 0; i < n; ++i)
        {
            cin >> x;
            data[i] = x;
            //data[i+n] = x;
        }
        //cout << n << endl;
        for(int i = 0; i < n ; ++i)
        {
            //cout << i << endl;
            if(good)
                break;
            if(!visited[i])
            {
                vector<int> s;
                int j = i;
                int left = 0;
                int su = 0;
                while(j < n)
                {
                    s.push_back(data[j]);
                    visited[j] = true;
                    j += data[j];
                    while(j-su - i > n && left < n)
                    {
                        su+=s[left++];
                    }
                    if(j-su-i == n)
                    {
                        good = true;
                        break;
                    }
                }
            }
        }
        if(good)
            cout << "ANO\n";
        else
        {
            cout << "NE\n";
        }
        
    }


}
