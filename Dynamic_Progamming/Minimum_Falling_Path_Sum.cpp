class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int> (m, 1e9));

        for( int i = 0; i < m; i++ ){
            dp[n-1][i] = matrix[n-1][i];
        }

        for( int i = n-2; i >= 0; i-- ){
            for( int j = 0; j < m; j++ ){
                int up = dp[i+1][j] + matrix[i][j];

                int leftup = matrix[i][j];
                if( j - 1 >= 0 ){
                    leftup += dp[i+1][j-1];
                }
                else{
                    leftup += 1e9;
                }

                int rightup = matrix[i][j];
                if( j + 1 < m ){
                    rightup += dp[i+1][j+1];
                }
                else{
                    rightup += 1e9;
                }

              dp[i][j] = min({ up, leftup, rightup });
            }
        }

        int mini = INT_MAX;

        for( int i = 0; i < m; i++ ){
            mini = min( mini, dp[0][i] );
        }

        return mini;
        
        
        
    }
};