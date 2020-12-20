#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, x,biggest, n;

    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        vector<int> d;
        cin >> n;
        vector<int> in(n+1,0);
        for(int j = 0; j < n; ++j)
        {
            cin >> x;
            in[j] = x;
        }
        sort(in.begin(), in.end());
        for(int j=0; j < n;++j)
        {
            d.push_back(abs(in[j]-in[j+1]));
        }
        biggest = *max_element(d.begin(), d.end());

        cout << biggest/2.0<<endl;
    }
    return 0;
}
