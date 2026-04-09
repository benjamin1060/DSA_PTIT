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

// find a node: log(N)
bool search(node *root, int key){
    if(root == NULL) return false;
    if(root->data == key) return true;
    else if(root->data < key){
        return search(root->right, key);
    }
    else return search(root->left, key);
}
// insert a new node
node *insert(node *root, int key){
    if(root = NULL) return makeNode(key);
    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else if(key > root->data){
        root->right = insert(root->right, key);
    }
    return root;
}
// delete a node
node* minNode(node *root){
    node *tmp = root;
    while(tmp != NULL && tmp->left != NULL){
        tmp = tmp -> left;
    }
    return tmp;
}
node* deleteNode(node *root, int key){
    if(root == NULL) return root;
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left == NULL){
            node *tmp = root->right;
            delete root;
            return tmp;
        }
        else if(root->right = NULL){
            node *tmp = root->left;
            delete root;
            return tmp;
        }
        else{
            node *tmp = minNode(root->right);
            root->data = tmp->data;
            root ->right = deleteNode(root->right, tmp->data);
        }
    }
    return root;
}
int main(){

}