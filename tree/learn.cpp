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
    node* newNode = new node;
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
void buildTree(node* &r, int u, int v, char c){
    if(r != NULL){
        if(r->data == u){
            if(c=='L') makeNode(v);
            else if(c=='R') makeNode(v);
        }
        buildTree(r->left,u,v,c);
        buildTree(r->right,u,v,c);
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
// level order
void levelOrder(node *root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *tmp = q.front();
        q.pop();
        cout << tmp -> data << ' ';
        q.push(tmp -> left);
        q.push(tmp -> right);
    }
}
void levelOrder2(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front(); q.pop();
        cout << tmp->data << ' ';
        q.push(tmp->left);
        q.push(tmp->right);
    }
}
void levelOrder2(node *root){
    queue<node*> q;
    q.push(root);
    cout << root -> data << ' ';
    while(!q.empty()){
        node *tmp = q.front(); q.pop();
        if(tmp -> left != NULL){
            q.push(tmp -> left);
            cout << tmp -> left -> data << ' ';
        }
        if(tmp -> right != NULL){
            q.push(tmp -> right);
            cout << tmp -> right -> data << ' ';
        }
    }
}
// spiral order
void spiral(node *root){
    stack<node*> s1, s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node *top = s1.top(); s1.pop();
            cout << top -> data << ' ';
            if(top->right != NULL){
                s2.push(top->right);
            }
            if(top->left != NULL){
                s2.push(top->left);
            }
        }
        while(!s2.empty()){
            node *top = s2.top(); s2.pop();
            cout << top -> data << ' ';
            if(top->left != NULL){
                s1.push(top->left);
            }
            if(top->right != NULL){
                s1.push(top->right);
            }
        }
    }
}
void spiralOrder2(node* r){
    stack<node*> s1, s2;
    s1.push(r);
    while(!s1.empty()||!s2.empty()){
        while(!s1.empty()){
            node* top = s1.top();s1.pop();
            cout << top->data << ' ';
            if(top->right != NULL){
                s2.push(top->right);
            }
            if(top->left != NULL){
                s2.push(top->left);
            }
        }
        while(!s2.empty()){
            node* top = s2.top();s2.pop();
            cout << top->data << ' ';
            if(top->left != NULL){
                s1.push(top->left);
            }
            if(top->left != NULL){
                s1.push(top->right);
            }
        }
    }
}
int main(){

    node *root = NULL;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v>> c;
        if(root == NULL){
            root = makeNode(u);
            makeRoot(root, u, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
        // inorder(root);
    }
}