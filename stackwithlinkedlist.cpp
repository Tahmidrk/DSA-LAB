#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
Node *top;
void push(int num){
    Node *newNode= new Node;
    newNode->data= num;
    newNode->next=NULL;
    newNode->next=top;
    top=newNode;
}
void pop(){
    if(top==NULL)return;
    Node *temp=top;
    top=top->next;
    delete temp;
}
void peek(){
    
    if(top!=NULL)
    cout<<"Top:"<<top->data<<endl;
}
void print(){
    Node *temp=top;
    cout<<"Data element in stack:";
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    push(5);
    push(10);
    push(15);
    push(20);
    print();
    pop();
    print();
    peek();
    
}