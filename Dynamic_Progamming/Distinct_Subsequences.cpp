// Solution 1 

class Solution {
public:
    
    int Fun( int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp ){

        if( ind2 < 0 ) return 1;
        else if( ind1 < 0 ) return 0;

        if( dp[ind1][ind2] != -1 ) return dp[ind1][ind2];

        if( s[ind1] == t[ind2] ){
            return dp[ind1][ind2] =  Fun( ind1-1, ind2-1, s, t, dp ) + Fun( ind1-1, ind2, s, t, dp );
        }
        else{
            return dp[ind1][ind2] = Fun( ind1-1, ind2, s, t, dp );
        }        
    }

    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp( n, vector<int> (m, -1));

        return Fun( n-1, m-1, s, t, dp );
    }
};


// Solution 2 

class Solution {
public:
    
    int prime = 1e9 + 7;

    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp( n+1, vector<int> (m+1, 0));

        for( int i = 0; i <= n; i++ ){
            dp[i][0] = 1;
        }

        for( int i = 1; i <= n; i++ ){
            for( int j = 1; j <= m; j++ ){

                if( s[i-1] == t[j-1] ){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % prime;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
};