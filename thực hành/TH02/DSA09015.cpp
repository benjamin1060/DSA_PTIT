#include<bits/stdc++.h>
using namespace std;
#define pb push_back

bool check;
inline void DFS(int x, vector<vector<int>> &a, vector<int> &b)
{
    if(check) return;
    b[x] = 1;
    for(int &i : a[x])
    {
        if(!b[i]) DFS(i, a, b);
        else if(b[i] == 1)
        {
            check = 1;
            return;
        }
    }
    b[x] = 2;
}
int main()
{
    int t = 1, e, v, x, y;
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        vector<vector<int>> a(v + 5);
        vector<int> b(v + 5, 0);
        check = 0;
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
        }
        for(int i = 1; i <= v; ++i)
        {
            if(check) break;
            else if(!b[i]) DFS(i, a, b);
        }
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}