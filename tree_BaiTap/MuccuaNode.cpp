#include <bits/stdc++.h>
using namespace std;

// cho cac muc cua node vao set
// node cung muc -> set co size = 1;
struct node{
    int data;
    node* left;
    node* right;
};
node* makeNode(int x){
    node* res = new node;
    res -> data = x;
    res -> left = res -> right = NULL;
    return res;
}
void buildTree(node* &root, char c, int par, int child){
    if(root != NULL)
    {
        if(root -> data == par)
        {
            if(c == 'L')
                root -> left = makeNode(child);
            else
                root -> right = makeNode(child);
        }
        buildTree(root -> left, c, par, child);
        buildTree(root -> right, c, par, child);
    }
}
set<int> se;
void tinhMuc(node* root, int cnt){
    if(root == NULL) return;
    if(root->left==NULL&&root->right==NULL){
        se.insert(cnt);
    }
    tinhMuc(root->left, cnt+1);
    tinhMuc(root->right, cnt+1);
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        node* root = NULL;
        int u, v; char c;
        cin >> u >> v >> c;
        root = makeNode(u);
        buildTree(root, c, u, v);
        n--;
        while(n--){
            cin >> u >> v >> c;
            buildTree(root, c, u, v);
        }
        tinhMuc(root, 0);
        if(se.size() == 1) cout << 1 << endl;
        else cout << 0 << endl;
        se.clear();
    }

}