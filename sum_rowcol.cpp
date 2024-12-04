#include<iostream>
using namespace std;

int main(){
    int r,c;
    int sum=0;
    cin>>r>>c;
    int a[r][c];

    cout<<"Enter array elements:"<<endl;;
    for (int i = 0; i < r; i++)
    {
        cout<<"Enter row "<<i+1<<":";
        for (int j = 0; j < c; j++)
        {
            cin>>a[i][j];
        }
        
    }
    cout<<"Row total:"<<endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum=sum+a[i][j];
        }
        cout<<sum<<" ";
        sum=0;
    }
    cout<<endl;
    cout<<"Column total:"<<endl;
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
            sum=sum+a[i][j];
        }
        cout<<sum<<" ";
        sum=0;
    }
    
}