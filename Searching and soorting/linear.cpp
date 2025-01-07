#include<iostream>
using namespace std;
int main()
{
    int a[100],n,x,i;
    cout<<"Enter size of an array:";
    cin>>n;
    cout<<"Enter array elements:";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter number to search in array:";
    cin>>x;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            cout<<"Element found at index:"<<i;
            break;
        }
    }
    if(i==n)
    {
        cout<<"Element not found in an array";
    }

    return 0;
}
