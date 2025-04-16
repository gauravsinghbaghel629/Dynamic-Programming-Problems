#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int total = 0;

    for(int i=0;i<n;i++){
        total += nums[i];
    }

    if(total % 2 == 1){
        return false;
    }
    else{
        int k = total / 2;
        vector<vector<bool>> dp(n,vector<bool> (k+1,false));

        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }

        if(nums[0] <= k) dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool notTaken = dp[i-1][target];
                bool taken = false;

                if(nums[i] <= target) taken = dp[i-1][target - nums[i]];

                dp[i][target] = notTaken | taken;
            }
        }
        return dp[n-1][k];
    }
}



int main() {
    vector<int> nums = {2, 3, 3, 3, 4, 5};
    int n = nums.size();

    if (canPartition(nums))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

    return 0;
}