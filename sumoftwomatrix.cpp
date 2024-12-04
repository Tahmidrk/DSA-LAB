#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter row & column:"<<endl;
    cin>>r>>c;
    int a[r][c],b[r][c],sum[r][c];
    
    

    cout<<"Enter array 1 elements:"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
  
      cout<<"Enter array 2 elements:"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>b[i][j];
        }
    }

     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            sum[i][j]=a[i][j]+b[i][j];
        }
        
    }
    cout<<"Sum matrix:"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
}
