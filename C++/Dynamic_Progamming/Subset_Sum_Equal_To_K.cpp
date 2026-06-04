// Solution 1

#include <bits/stdc++.h> 

bool Fun(int ind, int k, vector<int> &arr, vector<vector<int>> &dp){

    if( k == 0 ) return true;
    if( ind == 0 ) return ( arr[ind] == k );
    if( dp[ind][k] != -1 ) return dp[ind][k];

    bool nottake = Fun( ind - 1, k, arr, dp );
    bool take = false;
    if( arr[ind] <= k ){
        take = Fun( ind - 1, k-arr[ind], arr, dp );
    }

    return dp[ind][k] = (nottake | take) ;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
      vector<vector<int>> dp(n, vector<int> (k+1, -1));

      return Fun(n-1, k, arr, dp);
      
}


// Solution 2 


#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
      vector<vector<bool>> dp(n, vector<bool> (k+1, false));

      for( int i = 0; i < n; i++ ){
          dp[i][0] = true;
      }

      if(arr[0] <= k){
          dp[0][arr[0]] = true;
      }

      for( int ind = 1; ind < n; ind++ ){
          for( int target = 1; target <= k; target++ )
          {
              int nottake = dp[ind-1][target];

              int take = false;
              if(arr[ind] <= target){
                  take = dp[ind-1][target-arr[ind]];
              }

              dp[ind][target] = (nottake | take) ;
          }
      }
      
      return dp[n-1][k];
}