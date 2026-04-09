#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t, v, e, x, y;
    cin >> t;
    while(t--)
    {
        int degc[1005] = {}, degt[1005] = {};
        cin >> v >> e;
        while(e--)
        {
            cin >> x >> y;
            ++degc[x];
            ++degt[y];
        }
        int cnt = 0;
        bool check = 1;
        for(int i = 1; i <= v; ++i)
        {
            cnt += (abs(degc[i] - degt[i]) == 1);
            if(cnt > 2 or abs(degc[i] - degt[i]) > 1 or !degc[i] or !degt[i])
            {
                check = 0;
                break;
            }
        }
        if(check)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}