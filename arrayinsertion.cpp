#include<iostream>
using namespace std;
int main(){
    int k,i,n=5,a[10]={2,3,5,6,7};
    a[n++]=8;//at the end

    //at beginning

    for (int i = n; i > 0; i--)
    {
        a[i]=a[i-1];
    }
    a[0]=1;
    n++;

    //in a position
    k=3;
    for (int i = n; i > k; i--)
    {
        a[i]=a[i-1];
    }
    a[k]=4;
    n++;

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}

