#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"Enter row & column:"<<endl;
    cin>>r>>c;
    int a[r][c],b[r][c];
    
    

    cout<<"Enter array 1 elements:"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
  
   cout<<"Boundary element of 2D array:"<<endl;
   for (int i = 0; i < r; i++)
   {
     for (int j = 0; j < c; j++)
     {
       if(i == 0 ||i==r-1){
        cout<<a[i][j]<<" ";
       }
       else if(j==0||j==c-1){
        cout<<a[i][j]<< " ";
       }
       else {
        cout<< "  ";
     }

     
   }
   cout<<endl;
}
        cout<<"sum of the boundary elements of 2D array:"<<endl;
        int sum =0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (i==0||i==r-1)
                {
                    sum+=a[i][j];
                }
                else if (j==0||j==c-1)
                {
                    sum+=a[i][j];
                }
                
            }
            
        }
        cout<<sum<<endl;
}