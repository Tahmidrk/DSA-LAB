#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;
//Node *head=NULL;

void insertHead(int num){
    Node *newNode= new Node;
    newNode->data=num;
    newNode->next=NULL;
    newNode->next=head;
    head=newNode;
}
void insertLast(int num){
    Node *newNode= new Node;
    newNode->data=num;
    newNode->next=NULL;
    Node *temp=head;
    while (temp->next != NULL)
    {
        temp=temp->next;
    }
    
    newNode->next=temp->next;
    temp->next=newNode;
}
void insertPosition(int num,int afterValue){
    Node *newNode= new Node;
    newNode->data=num;
    newNode->next=NULL;
    Node *temp=head;
    while (temp->data!=afterValue)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void deletHead(){
    if (head==NULL)
    {
        return;
    }
    Node *temp=head;
    head=head->next;
    delete temp;
}
void deletLast(){
    if (head==NULL)
    {
        return;
    }
    Node *temp=head;
    Node *prev=NULL;
    while (temp->next!=NULL)
    {   
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
    
}
void deletPos(int num){
    if (head==NULL)
    {
        return;
    }
    Node *temp=head;
    Node *prev=NULL;
    while (temp->data!=num)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
}
void print(){
    Node *temp=head;
    cout<<"Data element in a single linked list:";
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    
    insertHead(5);
    insertHead(10);
    insertHead(15);
    insertHead(20);
    print();
    insertLast(11);
    print();
    insertPosition(12,15);
    print();
    deletHead();
    print();
    // deletPos(15);
    // print();
    deletLast();
    print();
    deletPos(12);
    print();
}