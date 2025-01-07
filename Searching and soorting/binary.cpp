#include<iostream>
using namespace std;
int a[1000],n,x,i,j;

void bubblesort()
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void input()
{
    cout<<"Enter size of an array:";
    cin>>n;
    cout<<"Enter array elements:";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void print()
{

    for(i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}

int binarysearch(int low,int high)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==x)
        {
            return mid;
        }

        else if(a[mid]>x)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main()
{
    cout<<"Before sorting"<<endl;
    input();
    print();
    bubblesort();
    cout<<"After sorting"<<endl;
    print();
    cout<<"Enter number to search in array:";
    cin>>x;
   int result=binarysearch(0,n-1);
    if(result==-1)
    {
        cout<<"Element not found in array";
    }
    else{
        cout<<"Element found at index:"<<result;
    }


    return 0;

}
