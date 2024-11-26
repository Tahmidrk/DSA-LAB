#include<iostream>
#include<string>
using namespace std;

class Mystack{
    char stack[100];
    int top;
    int maxSize;

    public:
    Mystack(int size){
        maxSize=size;
        top=0;
    }
    bool isEmpty(){
        if(top==0)return true;
        else return false;
    }
    bool isFull(){
        if(top==maxSize)return true;
        else return false;
    }
   
    void push(char x){
        if(isFull()){
            cout<<"Stack is full.";
        }
        else{
            stack[top]=x;
            top++;
        }
    }
    void pop(){
        if (isEmpty())
        {
            cout<<"Stack underflow";
        }
        else top--;
        
    }
    char peek(){
        return stack[top-1];
    }
   
};
 bool bracketPush(string str){
        Mystack p(100);
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i]=='(')
            {
                p.push(str[i]);
            }
            else if (str[i]==')')
            {
                if(p.isEmpty()){
                    return false;//closing extra bracket
                }
                 p.pop();
            }
           
        }
        return p.isEmpty();
    }
    int main(){
        string input;
        cout<<"Enter a string with parentheses:";
        cin>>input;

        if (bracketPush(input))
        {
            cout<<"The parentheses are balanced.";
        }
        else{
            cout<<"The parantheses are not balanced.";
        }
        return 0;
    }