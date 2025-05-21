#include<bits/stdc++.h>
using namespace std;
int P[100][100];
void knapsack(int W, int weight[], int value[], int n) {
    for(int i=0;i<n;i++){
        P[i][0]=0;
    }
    for(int w=0;w<=W;w++){
        P[0][w]=0;
    }

    for(int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(weight[i-1] <= w){
                if(value[i-1] + P[i-1][w-weight[i-1]] > P[i-1][w]){
                    P[i][w] = value[i-1] + P[i-1][w-weight[i-1]];
                }else{
                    P[i][w] = P[i-1][w];
                }
            }else{
                P[i][w] = P[i-1][w];
            }
        }
    }

    cout<<"Maximum value that can be obtained: "<<P[n][W]<<endl;
    cout<<"Items included in the knapsack: "<<endl;
    int i=n, w=W;
    while(i>0 && w>0){
        if(P[i][w] != P[i-1][w]){
            cout<<"Item "<<i<<" "<<weight[i-1]<<" "<<value[i-1]<<endl;
            w -= weight[i-1];
        }
        i--;
    }
}

int main() {
    int n,W;
    cout<<"enter number of items: ";
    cin>>n;

    int weight[n],value[n];
    cout<<"enter the weight and value: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"item "<<i+1<<": ";
        cin>>weight[i]>>value[i];
    }

    cout<<"enter max capacity: ";
    cin>>W;
    knapsack(W,weight,value,n);
    return 0;
}