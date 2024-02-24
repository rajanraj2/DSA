#include <iostream>
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
    else {
        root->right = insert(root->right, data);
    }
    return root;
};

int getHeight(Node *root){
    if (root == NULL){
        return -1;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void printEvenLevels(Node *root, int level){
    if (root == NULL){
        return;
    }
    if (level%2 == 0){
        cout<<root->data<<" ";
    }
    printEvenLevels(root->left, level+1);
    printEvenLevels(root->right, level+1);
}

void printOddLevels(Node *root, int level){
    if (root == NULL){
        return;
    }
    if (level%2 != 0){
        cout<<root->data<<" ";
    }
    printOddLevels(root->left, level+1);
    printOddLevels(root->right, level+1);
}

void printNodesAtLevelK(Node *root, int k){
    if (root == NULL){
        return;
    }
    if (k == 0){
        cout<<root->data<<" ";
    }
    printNodesAtLevelK(root->left, k-1);
    printNodesAtLevelK(root->right, k-1);
}

int  main(){
    int n,x;
    Node *root = NULL;
    cout<<"Enter no. of elements: "<<endl;
    cin>>n;
    cout<<"Enter the elements: "<<endl;
    for (int i=0;i<n;i++){
        cin>>x;
        root = insert(root, x);
    }
    cout<<"Height of the tree: "<<getHeight(root)<<endl;
    cout<<"Even levels: ";
    printEvenLevels(root, 0);
    cout<<endl;
    cout<<"Odd levels: ";
    printOddLevels(root, 0);
    cout<<endl;
    cout<<"Nodes at level 2: "; 
    printNodesAtLevelK(root, 2);
    return 0;
}