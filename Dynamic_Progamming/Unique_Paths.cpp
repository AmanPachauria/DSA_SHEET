// Solution 1

class Solution {
public:

    int Fun(int row, int col, vector<vector<int>> &dp){
        if( row == 0 && col == 0 ){
            return 1;
        }

        if( dp[row][col] != -1 ) return dp[row][col];

        int up = 0;
        int left = 0;
        if(row-1>=0){
            up += Fun( row-1, col, dp);
        }
        if(col-1>=0){
            left += Fun( row, col-1, dp);
        }

        return dp[row][col] = up + left;
    }

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return Fun(m-1, n-1, dp);
    }
};


// Solution 2


class Solution {
public:

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        for( int i = 0; i < n; i++ ){
            dp[0][i] = 1;
        }

        for( int i = 0; i < m; i++ ){
            dp[i][0] = 1;
        }

        for( int i = 1; i < m; i++ ){
            for( int j = 1; j < n; j++ ){
                dp[i][j] = max( dp[i][j-1] + dp[i-1][j], dp[i][j]);
            }
        }

        return dp[m-1][n-1];
    }
};