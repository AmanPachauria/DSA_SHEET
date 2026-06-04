// Solution 1

class Solution {
public:

    int Fun( int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if( row == 0 && col == 0 ){
            return grid[0][0];
        }

        if( row < 0 || col < 0 ){
            return INT_MAX-1e2;
        }

        if( dp[row][col] != -1 ) return dp[row][col];

        int up = grid[row][col] + Fun( row - 1, col, grid, dp );
        int left = grid[row][col] + Fun( row, col - 1, grid, dp);

        return dp[row][col] = min( up, left );
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

       return Fun( n-1, m-1, grid, dp );
    }
};

// Solution 2

class Solution {
public:

    

    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        dp[0][0] = grid[0][0];

        for( int i = 1; i < m; i++ ){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        for( int i = 1; i < n; i++ ){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for( int i = 1; i < n; i++ ){
            for( int j = 1; j < m; j++ ){
                dp[i][j] = min( grid[i][j] + dp[i-1][j], grid[i][j] + dp[i][j-1] );
            }
        }

        return dp[n-1][m-1];
    }
};