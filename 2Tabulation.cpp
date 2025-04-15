#include<bits/stdc++.h>
using namespace std;

int f(int ind,vector<int> &heights,int k,vector<int> &dp){
    int n = heights.size();
    dp[0] = 0;


    for(int i=1;i<n;i++){
        int minJumps = INT_MAX;

        for(int j=1;j<=k;j++){
            if(i-j >= 0){
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                minJumps = min(minJumps,jump);
            }
        }
        dp[i] = minJumps;
    }
    return dp[n-1];
}

int frogJumps(vector<int> &heights,int n,int k){
    vector<int> dp(n,-1);
    return f(n-1,heights,k,dp);
}

int main(){
    vector<int> heights{30, 10, 60, 10, 60, 50};

    int n = heights.size();
    int k = 2;

    int ans = frogJumps(heights,n,k);
    
    cout<<ans<<endl;

    return 0;
}