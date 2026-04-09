
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;

struct Node{
    char c;
    Node *left, *right;
};

typedef Node* Tree;

Tree makeNode(char c){
    Tree res = new Node;
    res -> c = c;
    res -> left = res -> right = NULL;
    return res;
}

void out(Tree x){
    if(x != NULL){
        out(x -> left);
        cout << x -> c;
        out(x -> right);
    }
}

int main(){
    int t; cin >> t;
    string s;
    while(t--){
        cin >> s;
        stack<Tree> st;
        for(char x : s){
            if(x == '+' || x == '-' || x == '*' || x == '/'){
                Tree tmp = makeNode(x);
                tmp -> right = st.top(); st.pop();
                tmp -> left = st.top(); st.pop();
                st.push(tmp);
            }
            else st.push(makeNode(x));
        }
        out(st.top());
        cout << endl;
    }
}

