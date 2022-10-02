#include <iostream>

using namespace std;

class Node{
friend class BST;

public:
    int data;
    Node *left, *right;
    Node(int value){
        data=value;
        left=0;
        right=0;
    }
};

class BST{
public:
    Node *root;
    BST(){root=0;}
    Node *insertTree(Node *ptr, int num);

};

Node *BST::insertTree(Node *ptr, int num){
    if(ptr==0){
        ptr=new Node(num);
        if(root==0) root=ptr;
    }
    else if(ptr->data > num) ptr->left=insertTree(ptr->left, num);
    else if(ptr->data < num) ptr->right=insertTree(ptr->right, num);
    return ptr;
}

void inOrder(Node* root){
    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
}

int main(){
    int t, n, val;
    cin >> t;
    for(int i=0; i<t; i++){
        BST bst;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> val;
            bst.insertTree(bst.root, val);
        } 
        inOrder(bst.root);
    }
    return 0;
}


// 5 3 4 5 1 2