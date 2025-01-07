/*Problem: Given an array of integers and a target value, determine if the target
exists in the array. If it does, return its position; otherwise, return -1.

Example:
Input: Array = [10, 20, 30, 40, 50], Target = 30
Output: Position = 2*/
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
