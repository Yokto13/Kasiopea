#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, c;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        cin >> a >> b >> c;
        if(a-c > b)
            cout << "REKLAMU"<<endl;
        else
        {
            cout << "NE REKLAMU"<<endl;
        }
    }
    return 0;
}
