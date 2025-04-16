#include<bits/stdc++.h>
using namespace std;


int minimumPathSum(vector<vector<int>> &triangle){
    int n = triangle.size();

    vector<int> front(n,0), curr(n,0);

    for(int j=0;j<n;j++){
        front[j] = triangle[n-1][j];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = triangle[i][j] + front[j];
            int diag = triangle[i][j] + front[j+1];

            curr[j] = min(down,diag);
        }
        front = curr;
    }
    return front[0];
}

int main() {
    // Define the triangle as a 2D vector
    vector<vector<int>> triangle{{1},
                                  {2, 3},
                                  {3, 6, 7},
                                  {8, 9, 6, 10}};

    // Get the number of rows in the triangle
    int n = triangle.size();

    // Call the minimumPathSum function and print the result
    cout << minimumPathSum(triangle);

    return 0;
}