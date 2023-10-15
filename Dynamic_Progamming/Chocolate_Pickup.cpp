// Solution 1 

#include <bits/stdc++.h> 

int Fun( int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    
    if( j1 < 0 || j2 < 0 || j1 >= m || j2 >= m ){
        return -1e8;
    }

    if( i == n-1 ){
        if( j1 == j2 ) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1 ) return dp[i][j1][j2];
    
    int maxi = INT_MIN;
    for( int dr = -1; dr <= 1; dr++ ){
        for( int dc = -1; dc <= 1; dc++ ){
            int value = 0;
            if( j1 == j2 ){
               value = grid[i][j1] + Fun( i + 1, j1 + dr, j2 + dc, n, m, grid, dp );
            } 
            else{
              value = grid[i][j1] + grid[i][j2] + Fun( i + 1, j1 + dr, j2 + dc, n, m, grid, dp );
            }
             
            
            maxi = max( maxi, value );
        }
    }

    return dp[i][j1][j2] = maxi;
}


int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));

    return Fun( 0, 0, c-1, r, c, grid, dp );
}


// Solution 2


#include <bits/stdc++.h> 

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, 0)));
    
    int n = r, m = c;
    for( int j1 = 0; j1 < m; j1++ ){
        for( int j2 = 0; j2 < m; j2++ ){
            if( j1 == j2 ){
                dp[n-1][j1][j2] = grid[n-1][j1];
            }
            else{
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }

    for( int i = n-2; i >= 0; i-- ){
        for( int j1 = 0; j1 < m; j1++ ){
            for( int j2 = 0; j2 < m; j2++ ){
                int maxi = INT_MIN;
                
                for( int dr = -1; dr <= 1; dr++ ){
                    for( int dc = -1; dc <= 1; dc++ ){
                         
                         int ans;
                         if( j1 == j2 ) ans = grid[i][j1];
                         else ans = grid[i][j1] + grid[i][j2];

                         if( j1+dr < 0 || j1+dr>=m || j2+dc<0 | j2+dc>=m ){
                             ans += -1e9;
                         }
                         else{
                             ans += dp[i+1][j1+dr][j2+dc];
                         }

                         maxi = max(maxi, ans);
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m-1];
    
}