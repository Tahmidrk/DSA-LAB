#include<bits/stdc++.h>
using namespace std;

struct student
{
    string name;
    string id;
    double cgpa;
};

int main(){
    int n;
    cout<<"Enter the number of student:"<<endl;
    cin>>n;
    student s[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the details of student "<<i+1<<":"<<endl;
        cout<<"Name: ";
        getline(cin >> ws, s[i].name);
        cout<<"Id: ";
        cin>>s[i].id;
        cout<<"CGPA:";
        cin>>s[i].cgpa;

        cout<<"Details of student "<<i+1<<":"<<endl;
        cout<<"Name: "<<s[i].name<<endl;
        cout<<"ID:"<<s[i].id<<endl;
        cout<<"CGPA:"<<s[i].cgpa<<endl;

    }
    return 0;
}