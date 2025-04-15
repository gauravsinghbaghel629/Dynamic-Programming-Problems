#include<bits/stdc++.h>
using namespace std;

int fibbo(int n,vector<int> &dp){
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    int last = fibbo(n-1,dp);
    int slast = fibbo(n-2,dp);

    return dp[n] = last + slast;
}

int main(){
    int n;
    cin>>n;

    vector<int> dp(n+1,-1);
    int ans = fibbo(n,dp);

    cout<<ans;

    return 0;
}