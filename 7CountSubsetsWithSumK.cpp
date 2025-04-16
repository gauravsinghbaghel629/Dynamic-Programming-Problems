#include<bits/stdc++.h>
using namespace std;

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (k+1,0));

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }

    if(arr[0] <= k){
        dp[0][arr[0]] = 1;
    }

    for(int i=1;i<n;i++){
        for(int tar=1;tar <= k;tar++){
            int notTaken = dp[i-1][tar];
            int taken = 0;

            if(arr[i] <= tar) taken = dp[i-1][tar - arr[i]];

            dp[i][tar] = notTaken + taken;
        }
    }

    return dp[n-1][k];
}


int main() {
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}