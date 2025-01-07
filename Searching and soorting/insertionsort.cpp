#include<iostream>
using namespace std;

void insertionsort(int a[],int n){
    int i,j,key;
    for (int i=1; i < n; i++)
    {
        int key=a[i];
        int j=i-1;

        while (j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    
}

void output(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int a[]={12,11,13,5,6};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<"Before sorting:";
    output(a,n);
    insertionsort(a,n);

    cout<<"After sorting:";
    output(a,n);

    return 0;
}
