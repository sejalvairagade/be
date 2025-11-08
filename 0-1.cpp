#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int val[n], wt[n], W;

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    cout << "\nMaximum value that can be put in knapsack = "
         << knapsack(W, wt, val, n);

    return 0;
}









































#include<iostream>
using namespace std;

int knapsack(int W,int val[],int wt[],int n){
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int w=0;w<=n;w++){
            if(i==0 || w==0){
                dp[i][w]=0;
            }
            else if (wt[i-1]<=w){
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }

        }
    }

}

int main(){
    int n;
    cout<<"enter the no of items";
    cin>>n;

    int val[n],wt[n],W;

    cout<<"enter the value:";
    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    cout<<"enter the weight:";
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    cout<<"enter the capacity:";
    cin>>W;

    cout<<"max value that can be put in the knapsack:";
    cout<<knapsack(W,wt,val,n);
    return 0;

}