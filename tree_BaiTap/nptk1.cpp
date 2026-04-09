#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
};
node* makeNode(int x){
    node* res = new node;
    res -> val = x;
    res -> left = res -> right = NULL;
    return res;
}

void buildTree(node* &x, int val){
    if(x == NULL){
        x = makeNode(val);
        return;
    }
    if(x -> val > val)
        buildTree(x -> left, val);
    else
        buildTree(x -> right, val);
}

void order(node* x){
    if(x != NULL){
        order(x -> left);
        order(x -> right);
        cout << x -> val << ' ';
    }
}
int main(){
    int test, n, val;
    cin >> test;
    while(test--){
        cin >> n;
        node* T = NULL;
        while(n--){
            cin >> val;
            buildTree(T, val);
        }
        order(T);
        cout << endl;
    }
}
/*

*/