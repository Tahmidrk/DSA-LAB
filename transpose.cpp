#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter row & column:"<<endl;
    cin>>r>>c;
    int a[r][c],transpose[r][c];
    
    

    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            transpose[j][i]=a[i][j];
        }
        
    }

    cout<<"Transpose matrix:"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
}
