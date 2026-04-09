#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};
node* makeNode(int u){
    node* newNode = new node;
    newNode->data = u;
    newNode->left=newNode->right = NULL;
    return newNode;
}
void buildTree(node* &root, int u, int v, char c){
    if(root != NULL){
        if(root->data==u){
            if(c=='L'){
                root->left = makeNode(v);
            }
            else root->right = makeNode(v);
        }
        buildTree(root->left, u, v, c);
        buildTree(root->right, u, v, c);
    }
}
bool check;
long long sum;
bool isleaf(node* root){
    return root->left==root->right&&root->left==NULL;
}
void cal(node* root){
    if(root == NULL) return;
    if(root->right!=NULL&&isleaf(root->right)){
        sum+=root->right->data;
    }
    if(root->right!=NULL&&!isleaf(root->right)){
        cal(root->right);
    }
    if(root->left!=NULL&&!isleaf(root->left)){
        cal(root->left);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int u, v; char c;
        cin >> u >> v >> c;
        node* root = NULL;
        root = makeNode(u);
        buildTree(root, u, v, c);
        n--;
        while(n--){
            cin >> u >> v >> c;
            buildTree(root, u, v, c);
        }
        sum = 0;
        cal(root);
        cout << sum << endl;
        delete root;
    }
    return 0;
}