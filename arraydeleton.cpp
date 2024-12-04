#include<iostream>
using namespace std;
int main(){
    int k,i,n=8,a[10]={1,2,3,4,5,6,7,8};
    n--;//at the end

    //at beginning
    n--;
    for (int i = 0; i < n; i++)
    {
        a[i]=a[i+1];
    }
    

    //in a position
    k=2;
    n--;
    for (int i = k; i < n; i++)
    {
        a[i]=a[i+1];
    }
   

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}

