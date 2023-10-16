int mod = 1e9 + 7;

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (k+1, 0));

    for( int i = 0; i < n; i++ ){
        dp[i][0] = 1;
    }

    if( arr[0] <= k ){
        dp[0][arr[0]] = 1;
    }

    for( int ind = 1; ind < n; ind++ ){
        for( int target = 1; target <= k; target++ ){
            
            int nottake = dp[ind-1][target];
            
            int take = 0;
            if( arr[ind] <= target ){
                take = dp[ind-1][target - arr[ind]];
            }

            dp[ind][target] = ( nottake + take ) % mod;
        }
    }

    return dp[n-1][k];
}
