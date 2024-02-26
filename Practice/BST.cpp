#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node *&root, int data){
    if (root == NULL){
        return new Node(data);
    }
    else if (data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
}

void inorder(Node *root){
    if (root==NULL){
        return;
    }
    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);
}

int findmin(Node *root){
    if (root == NULL){
        cout<<"Tree is empty."<<endl;
    }
    while (root->left!=NULL){
        root = root->left;
    }
    return root->data;
}

int main(){
    int n,x;
    Node *root=NULL;
    cout<<"Enter no. of elements: "<<endl;
    cin>>n;
    cout<<"Enter the elements: "<<endl;
    for (int i=0;i<n;i++){
        cin>>x;
        root = insert(root,x);
    }
    return 0;
}