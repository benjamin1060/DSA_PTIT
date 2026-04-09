#include <bits/stdc++.h>
using namespace std;

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
int demNodeLa(node* root){
    if(root == NULL) return 0;
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int dem = 0;
    dem += demNodeLa(root->left);
    dem += demNodeLa(root->right);
    return dem;
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
}