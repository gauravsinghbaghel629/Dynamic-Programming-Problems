#include<bits/stdc++.h>
using namespace std;

int f(int ind,vector<int> &heights,int k,vector<int> &dp){
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int minJumps = INT_MAX;

    for(int j=1;j<=k;j++){
        if(ind - j >= 0){
            int jump = f(ind-j,heights,k,dp) + abs(heights[ind] - heights[ind-j]);
            minJumps = min(minJumps,jump);
        }
    }
    return dp[ind] = minJumps;
}

int frogJumps(vector<int> &heights,int n,int k){
    vector<int> dp(n+1,-1);
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