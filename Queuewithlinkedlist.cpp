#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
Node *front = NULL, *rear = NULL;

void enqueue(int num){
    Node *newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;
    if(rear == NULL){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue(){
    if(front == NULL) return;
    Node *temp = front;
    front = front->next;
    if(front == NULL) rear = NULL;
    delete temp;
}

void peek(){
    if(front != NULL)
        cout << "Front:" << front->data << endl;
}

bool isEmpty(){
    return front == NULL;
}

void print(){
    Node *temp = front;
    cout << "Data elements in queue:";
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    print();
    dequeue();
    print();
    peek();
}
