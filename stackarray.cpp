#include<iostream>
#include<string>
using namespace std;

class Mystack{
    int stack[100];
    int top;
    int maxSize;

    public:
    Mystack(int size){
        maxSize=size;
        top=0;
        cout<<"Maxsize: ";
        cout<<top;
    }
    bool isEmpty(){
        if(top==0)return true;
        else return false;
    }

    bool isFull(){
        if(top==maxSize)return true;
        else return false;
    }
    void push(int n){
        if(isFull()){
            cout<<"Stack is full.";
        }
        else{
            stack[top]=n;
            top++;
        }
    }
    void pop(){
        if (isEmpty())
        {
            cout<<"Stack is empty";
        }
        else { top--;
        }
        
    }
    int topElement(){
        return stack[top-1];
    }
    void show(){
        if(isEmpty()){
            cout<<"Stack is empty";
        }
        else{
            for (int i = top-1; i >=0 ; i--)
            {
                cout<<stack[i]<<" ";
            }
            
        }
    }
};
int main(){
    Mystack s(100);
    s.show();
    cout<<s.isFull();
    cout<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.show();
    s.pop();
    cout<<endl;
    s.show();
}