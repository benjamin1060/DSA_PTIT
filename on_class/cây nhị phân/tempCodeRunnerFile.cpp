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