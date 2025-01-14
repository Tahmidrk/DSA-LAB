#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node * right;

    Node(int d){
        data = d;
        left=NULL;
        right=NULL;
    }

};

void inorder(Node* root){
    if (root!=NULL)
    {
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
    Node *a= new Node(1);
    Node *b=a->left=new Node(2);
    Node *c=a->right=new Node(3);
    Node *d=b->left=new Node(4);
    Node *e=b->right=new Node(5);
    Node *f=c->left=new Node(6);
    Node *g=c->right=new Node(7);

    cout<<"Inorder Traversal: ";
    inorder(a);
    cout<<endl;

    cout<<"Preorder Traversal: ";
    preorder(a);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    postorder(a);
    cout<<endl;
}
/*       1
       /   \
      2     3
     / \   / \
    4   5 6   7
*/
