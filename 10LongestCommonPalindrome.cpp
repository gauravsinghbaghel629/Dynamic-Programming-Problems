#include<bits/stdc++.h>
using namespace std;

int lcs(string &s,string &t){
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(t.begin(),t.end());

    return lcs(s,t);
}

int main() {
    string s = "bbabcbcab";

    // Call the longestPalindromeSubsequence function and print the result
    cout << "The Length of Longest Palindromic Subsequence is " << longestPalindromeSubseq(s);
    return 0;
}