#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

Node *insert(Node* root,int d){
    if (root==NULL)
    {
        return new Node(d);
    }
    if (d<root->data)
    {
        root->left=insert(root->left,d);
    }
    else{
        root->right=insert(root->right,d);
    }
    return root;
}

bool search(Node* root,int d){
    if (root==NULL)
    {
        return false;
    }
    if (root->data==d)
    {
        return true;
    }
    else if (d<root->data)
    {
        return search(root->left,d);
    }
    else{
        return search(root->right,d);
    }
    
}
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node* root){
    if (root!=NULL)
    {
        cout<<root->data<<" "; 
        preorder(root->left);
        preorder(root->right);
         
    }
    
}

void postorder(Node* root){
    if (root!=NULL)
    {
        
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";  
    }
    
}
int main(){
    Node* root=NULL;

    root=insert(root,50); 
    root=insert(root,30);
    root=insert(root,70);
    root=insert(root,20);
    root=insert(root,40);   
    root=insert(root,60);
    root=insert(root,80);

    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    postorder(root);
    cout<<endl;

       int value;
    cout << "Enter a value to search: ";
    cin >> value;
    if (search(root, value)) {
        cout << "Value " << value << " found in the BST!" << endl;
    } else {
        cout << "Value " << value << " not found in the BST!" << endl;
    }

    return 0;
}
