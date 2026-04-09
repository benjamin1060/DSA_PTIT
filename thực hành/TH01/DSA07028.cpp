#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> a(n + 5), c(n + 5);
        stack<int> st;
        for(int i = 1; i <= n; ++i) cin >> c[i];
        for(int i = 1; i <= n; ++i)
        {
            while(st.size() && c[i] >= c[st.top()]) st.pop();
            if(st.empty()) a[i] = 0;
            else a[i] = st.top();
            st.push(i);
        }
        for(int i = 1; i <= n; ++i) cout << i - a[i] << ' ';
        cout << endl;
    }
    return 0;
}