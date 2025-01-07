/*Problem: Given an array of integers, count how many times a specified
element appears.

Example:
Input: Array = [1, 2, 3, 4, 2, 2, 5], Target = 2
Output: Count = 3*/

#include<iostream>

using namespace std;

int main(){
    int array[]={1,2,3,4,2,2,5};
    int size=sizeof(array)/sizeof(array[0]);
    int target=2;
    int count=0;

    for (int i = 0; i < size; i++)
    {
        if (array[i]==target)
        {
            count++;
        }
        
    }
    cout<<"Count:"<<count<<endl;
    return 0;
    
}
//output:Count:3
