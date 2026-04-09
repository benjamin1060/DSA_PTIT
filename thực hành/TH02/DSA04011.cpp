#include<bits/stdc++.h>
using namespace std;
#define sz size()
#define ll long long

inline ll binPow(ll b)
{
    if(!b) return 1;
    if(b == 1) return 2;
    ll res = binPow(b >> 1);
    res *= res;
    if(b & 1) res <<= 1;
    return res;
}

inline ll change(string &s)
{
    ll res = 0;
    for(int i = 0, j = s.sz - 1; i < s.sz; ++i, --j) if(s[i] == '1') res += binPow(j);
    return res;
}

int main()
{
    int t = 1;
    string s1, s2;
    cin >> t;
    while(t--)
    {
        cin >> s1 >> s2;
        cout << change(s1) * change(s2) << endl;
    }
    return 0;
}