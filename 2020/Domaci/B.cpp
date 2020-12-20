#include<bits/stdc++.h>

using namespace std;

int custum_max(int a, int b,int c)
{
    return max(max(a,b),max(b,c));
}

int main()
{
    int t;
    int n;
    int best, x;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        best = 41; // Temp is always atmost 40.
        cin >> n;
        vector<int> v(n,0);
        for(int j = 0; j < n ; ++j)
        {
            cin >> x;
            v[j] = x;
            if(j>=2)
            {
                best = min(best, custum_max(v[j],v[j-1],v[j-2]));
            }
        }
        cout << best <<endl;
    }
    return 0;
}
