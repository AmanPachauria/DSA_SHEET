// Solution 1


class Solution {
public:

    int Fun( int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if( row == 0 && col == 0 && grid[row][col] == 0 ){
            return 1;
        } 
        if( dp[row][col] != -1 ) return dp[row][col];

        int up = 0, left = 0;
        if( row - 1 >= 0 && grid[row-1][col] == 0 ){
            up += Fun( row-1, col, grid, dp);
        }
        if( col - 1 >= 0 && grid[row][col-1] == 0 ){
            left += Fun( row, col-1, grid, dp);
        }

        return dp[row][col] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if( obstacleGrid[n-1][m-1]==1 ) return 0;

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return Fun(n-1, m-1, obstacleGrid, dp);
        
    }
};

// Solution 2


class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        // if( obstacleGrid[n-1][m-1]==1 ) return 0;

        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        for( int i = 0; i < m; i++ ){
            if( obstacleGrid[0][i] == 1 ) break;
            dp[0][i] = 1;
        }

        for( int i = 0; i < n; i++ ){
             if( obstacleGrid[i][0] == 1 ) break;
             dp[i][0] = 1;
        }

        for( int i = 1; i < n; i++ ){
            for( int j = 1; j < m; j++ ){
                if( obstacleGrid[i][j] == 1 ) continue;
                dp[i][j] = max( dp[i-1][j] + dp[i][j-1], dp[i][j] );
            }
        }

        return dp[n-1][m-1];
        
    }
};

