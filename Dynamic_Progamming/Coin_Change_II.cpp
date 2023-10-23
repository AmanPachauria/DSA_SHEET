// Solution 1 

class Solution {
public:
    
    int Findways( int ind, int target, vector<int> &arr, vector<vector<int>> &dp ){

        if( ind == 0 ){
            if( target == 0 && arr[0] == 0 ) return 2;
            else if( target % arr[0] == 0  || target == 0 ) return 1;
            else return 0;
        }

        if( dp[ind][target] != -1 ) return dp[ind][target];

        int nottake = Findways( ind-1, target, arr, dp );
        int take = 0;
        if( arr[ind] <= target ){
            take = Findways( ind, target - arr[ind], arr, dp );
        }

       return dp[ind][target] = nottake + take;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return Findways( n-1, amount, coins, dp );   
    }
};


// Solution 2 


class Solution {
public:

    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for( int i = 0; i <= amount; i++ ){
            if( i % coins[0] == 0 ){
                dp[0][i] = 1;
            }
        }

        for( int ind = 1; ind < n; ind++ ){
            for( int target = 0; target <= amount; target++ ){

                int nottake = dp[ind-1][target];
                int take = 0;
                if( coins[ind] <= target ){
                    take = dp[ind][target-coins[ind]];
                } 

                dp[ind][target] = nottake + take;
            }
        }

        return dp[n-1][amount];
    }
};