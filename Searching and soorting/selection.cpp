#include<iostream>
using namespace std;

void selectionsort(int a[],int n){
    for (int i = 0; i < n-1; i++)
    {
        int minindex=i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j]<a[minindex])
            {
                minindex=j;
            }
            
        }
        if (minindex!=i)
        {
            int temp=a[i];
            a[i]=a[minindex];
            a[minindex]=temp;
        }
        
    }
    
}

void output(int a[],int n){
    for (int  i = 0; i < n; i++)
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
    selectionsort(a,n);

    cout<<"After sorting:";

    output(a,n);
}