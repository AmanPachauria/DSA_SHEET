// Solution 1 

class Solution {
public:

    int Fun( int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp ){
        
        if( ind1 == 0 || ind2 == 0 ) return 0;
        
        if( dp[ind1][ind2] != -1 ) return dp[ind1][ind2];

        if( str1[ind1-1] == str2[ind2-1] ){
            return 1 + Fun( ind1 - 1, ind2 - 1, str1, str2, dp );
        }

        return dp[ind1][ind2] = max( Fun( ind1-1, ind2, str1, str2, dp ), Fun( ind1, ind2-1, str1, str2, dp ));
    }

    int longestCommonSubsequence(string text1, string text2) {
         
         int n = text1.size(), m = text2.size();
         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

         return Fun( n, m, text1, text2, dp );   
    }
};


// Solution 2 


class Solution {
public:

    int Fun( int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp ){
        
        if( ind1 == 0 || ind2 == 0 ) return 0;
        
        if( dp[ind1][ind2] != -1 ) return dp[ind1][ind2];

        if( str1[ind1-1] == str2[ind2-1] ){
            return 1 + Fun( ind1 - 1, ind2 - 1, str1, str2, dp );
        }

        return dp[ind1][ind2] = max( Fun( ind1-1, ind2, str1, str2, dp ), Fun( ind1, ind2-1, str1, str2, dp ));
    }

    int longestCommonSubsequence(string text1, string text2) {
         
         int n = text1.size(), m = text2.size();
         vector<vector<int>> dp(n+1, vector<int>(m+1));

         for( int i = 0; i < m; i++ ){
             dp[0][i] = 0;
         } 
         
         for( int i = 0; i < n; i++ ){
             dp[i][0] = 0;
         }

         for( int i = 1; i <= n; i++ ){
             for( int j = 1; j <= m; j++ ){
                   
                   if( text1[i-1] == text2[j-1] ){
                       dp[i][j] = 1 + dp[i-1][j-1];
                   }
                   else{
                       dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
                   }
             }
         }

         return dp[n][m];
    }
};