#include<bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2){
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    int ans = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}


int main() {
    string str1 = "abcjklp";
    string str2 = "acjkp";

    // Call the function to find and output the length of the Longest Common Substring
    cout << "The Length of Longest Common Substring is " << lcs(str1, str2) << endl;

    return 0; // Return 0 to indicate successful program execution
}
