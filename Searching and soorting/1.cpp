#include<iostream>
using namespace std;

int main(){
    int array[]={12,45,2,67,34};
    int size=sizeof(array)/sizeof(array[0]);

    int max=array[0];
    int min=array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i]>max)
        {
            max=array[i];
        }
        if (array[i]<min)
        {
            min=array[i];
        }
        
    
}
cout<<"Maximum value is:"<<max<<endl;
cout<<"Minimum value is:"<<min<<endl;
return 0;
}