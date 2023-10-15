// Solution 1

class Solution {
public:

    int Fun( int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp ){
        if(row==dp.size()-1){
            return triangle[row][col];
        }

        if(row >= dp.size()-1 ) return 0;

        if(dp[row][col]!=-1) return dp[row][col];

        int down = triangle[row][col] + Fun( row+1, col, triangle, dp );
        int downleft = triangle[row][col] + Fun( row+1, col+1, triangle, dp );

        return dp[row][col] = min( down, downleft);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        return Fun( 0, 0, triangle, dp );
    }
};


// Solution 2


class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));

        for( int i = 0; i < m; i++ ){
            dp[n-1][i] = triangle[n-1][i];
        }

        for( int i = n-2; i >= 0; i-- ){
            for( int j = 0; j < triangle[i].size(); j++ ){
                dp[i][j] = min( triangle[i][j] + dp[i+1][j], triangle[i][j] + dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};