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
void makeRoot(node *root, int u, int v, char c){
    if (c == 'L') root->left = makeNode(v);
    else root->right = makeNode(v);
}
void insertNode(node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->data == u){
        makeRoot(root, u, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}
int countLeaf(node* root){
    if(root = NULL) return 0;
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int cnt = 0;
    cnt += countLeaf(root->left);
    cnt += countLeaf(root->right);
}
int main(){
    node* root = NULL;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == NULL){
            root = makeNode(u);
            makeRoot(root, u, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }
    cout << countLeaf(root) << endl;

    return 0;
}