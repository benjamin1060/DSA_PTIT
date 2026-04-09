#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;

    // constructor
    // node(int x){
    //     data = x;
    //     left = right = NULL:
    // }
};
node* makeNode(int x){
    node *newNode = new node;
    newNode -> data = x;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}
// 12L13R
// assign v is u's child node
void insertNode(node *root, int u, int v, char c){
    if (c == 'L') root -> left = makeNode(v);
    else root -> right = makeNode(v);
}
// u is ancestor of v... find v through root
void makeRoot(node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root -> data == u){
        insertNode(root, u, v, c);
    }
    else{
        makeRoot(root -> left, u, v, c);
        makeRoot(root -> right, u, v, c);
    }
}
// inorder 
void inorder(node *root){
    if(root != NULL){
        inorder(root -> left);
        cout << root -> data << ' ';
        inorder(root -> right);
    }
}
// preorder
void preorder(node *root){
    if(root != NULL){
        cout << root -> data << ' ';
        preorder(root -> left);
        preorder(root -> right);
    }
}
// postorder
void postorder(node *root){
    if(root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << ' ';
    }
}

int main(){

    // node *root = NULL;
    // int n; cin >> n;
    // for(int i = 0; i < n; i++){
    //     int u, v; char c;
    //     cin >> u >> v>> c;
    //     if(root == NULL){
    //         root = makeNode(u);
    //         makeRoot(root, u, v, c);
    //     }
    //     else{
    //         insertNode(root, u, v, c);
    //     }
    //     // inorder(root);
    // }

    node* s = makeNode(5);
    s->left = makeNode(2);
    s->right = makeNode(7);
    s->left->left = makeNode(1);
    s->left->right = makeNode(3);
    s->right->left = makeNode(6);
    s->right->right = makeNode(8);

    inorder(s); cout << endl;
    preorder(s); cout << endl;
    postorder(s); cout << endl;

}