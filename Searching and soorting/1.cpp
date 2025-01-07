/*Problem: Use linear search to find the maximum or minimum element in an
array.

Example:
Input: Array = [12, 45, 2, 67, 34]
Output: Maximum = 67, Minimum = 2*/
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
/*output:
Maximum value is:67
Minimum value is:2*/
