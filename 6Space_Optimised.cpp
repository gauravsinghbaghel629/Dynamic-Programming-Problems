#include<bits/stdc++.h>
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
        vector<bool> prev(k+1,false), curr(k+1,false);

        prev[0] = curr[0] = true;

        if(nums[0] <= k) prev[nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool notTaken = prev[target];
                bool taken = false;

                if(nums[i] <= target) taken = prev[target - nums[i]];

                curr[target] = notTaken | taken;
            }
            prev = curr;
        }
        return prev[k];
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