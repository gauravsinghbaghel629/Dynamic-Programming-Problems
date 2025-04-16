#include<bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m,0),curr(m,0);

    for(int j=0;j<m;j++){
        prev[j] = matrix[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up = matrix[i][j] + prev[j];

            int leftDiag = matrix[i][j];
            if(j-1 >= 0) leftDiag += prev[j-1];
            else leftDiag += -1e9;

            int rightDiag = matrix[i][j];
            if(j+1 < m) rightDiag += prev[j+1];
            else rightDiag += -1e9;

            curr[j] = max(up,max(leftDiag,rightDiag));
        }
        prev = curr;
    }

    int maxi = INT_MIN;

    for(int j=0;j<m;j++){
        maxi = max(maxi,prev[j]);
    }

    return maxi;
}

int main(){
    vector<vector<int>> matrix{{1, 2, 10, 4},
                               {100, 3, 2, 1},
                               {1, 1, 20, 2},
                               {1, 2, 2, 1}};

    // Call the getMaxPathSum function and print the result
    cout << getMaxPathSum(matrix);

    return 0;
}