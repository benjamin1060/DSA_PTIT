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
    node* newNode = new node;
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void insertNode(node* root, int u, int v, char c){
    if(c=='L') root->left = makeNode(v);
    else root->right = makeNode(v);
}
void makeRoot(node* root, int u, int v, char c){
    if(root->data == NULL) return;
    else if(root->data == u) 
        insertNode(root, u, v, c);
    else if(root->data < u) 
        makeRoot(root->left, u, v, c);
    else if(root->data > u) 
        makeRoot(root->right, u, v, c);
}
set<int> se;
int check = 1;
void tinhMuc(node* root, int cnt){
    if(root == NULL) return;
    if(root->left==NULL&&root->right!=NULL
        ||root->left!=NULL&&root->right==NULL){
            check = 0;
        }
    if(root->left==NULL&&root->right==NULL){
        se.insert(cnt);
    }
    tinhMuc(root->left, cnt+1);
    tinhMuc(root->right, cnt+1);
}
int main(){
    int n; cin >> n;
    node* root = NULL;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == NULL){
            makeRoot(root, u, v, c);
        }
        else insertNode(root, u, v, c);
    }
    tinhMuc(root, 0);
    if(check == 1){
        if(se.size()==1) cout <<"YES"<<endl;
        else cout << "NO" << endl;
    }       
    else cout << "NO" << endl;
}