
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t, v, e, x, y;
    cin >> t;
    while(t--)
    {
        int deg[1005] = {};
        cin >> v >> e;
        while(e--)
        {
            cin >> x >> y;
            ++deg[x];
            ++deg[y];
        }
        int cnt = 0;
        for(int i = 1; i <= v; ++i)
            cnt += deg[i] & 1;
        if(!cnt)
            cout << 2 << endl;
        else if(cnt == 2)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}