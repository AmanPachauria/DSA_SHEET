// Solution 1


class Solution {
public:
    
    int Fun( int ind, int amount, vector<int> &coins, vector<vector<int>> &dp ){
         
         if( ind == 0 ){
             if( amount%coins[ind] == 0 ) return amount/coins[ind];
             
             return 1e9;
         }

         if( dp[ind][amount] != -1 ) return dp[ind][amount];

         int nottake = 0 + Fun( ind -1, amount, coins, dp );
         int take = 1e9;
         if( coins[ind] <= amount ){
             take = 1 + Fun( ind, amount - coins[ind], coins, dp );
         }

         return dp[ind][amount] = min( take, nottake );
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1 ));

        int ans = Fun( n-1, amount, coins, dp );

        return ( ans>=1e9 ) ?  -1 : ans ;
    }
};



// Solution 2


class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
       
       int n = coins.size();
       vector<vector<int>> dp(n, vector<int> (amount+1, 0));

       for( int i = 1; i <= amount; i++ ){
           if( i%coins[0] == 0 ){
               dp[0][i] = i/coins[0];
           }
           else dp[0][i] = 1e9;
       }
      
       for( int i = 1; i < n; i++ ){
           for( int target = 1; target <= amount; target++ ){

               int nottake = dp[i-1][target];
               int take = 1e9;
               if( coins[i] <= target ){
                   take = 1 + (dp[i][target - coins[i]] );
               }

               dp[i][target] = min( nottake, take );
           }
       }
       
       int ans = dp[n-1][amount];

       return (ans >= 1e9 ) ? -1 : ans;
    }
};