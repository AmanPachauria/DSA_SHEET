// Solution 1

class Solution {
public:
    
    bool Fun( int ind, int sum , vector<int> &nums, vector<vector<int>> &dp ){

        if( sum == 0 ) return true;
        if( ind == 0 ) return ( nums[ind] == sum );
        
        if( dp[ind][sum] != -1 ) return dp[ind][sum];

        bool nottake = Fun( ind-1, sum, nums, dp );
        bool take = false;
        if( nums[ind] <= sum ){
            take = Fun( ind-1, sum - nums[ind] , nums, dp);
        }

        return dp[ind][sum] = (nottake | take);
    }

    bool canPartition(vector<int>& nums) {
       
       int n = nums.size();
       int sum = 0;
       for( int i = 0; i < n; i++ ){
           sum += nums[i];
       }

       if( sum&1 ) return false;
       else sum /= 2;

       vector<vector<int>> dp(n, vector<int> (sum+1, -1));

       return Fun(n-1, sum , nums, dp);
    }
};

// Solution 2

class Solution {
public:

    bool canPartition(vector<int>& nums) {
       
       int n = nums.size();
       int sum = 0;
       for( int i = 0; i < n; i++ ){
           sum += nums[i];
       }

       if( sum&1 ) return false;
       else sum /= 2;

       vector<vector<bool>> dp(n, vector<bool> (sum+1, false));

       for( int i = 0; i < n; i++ ){
           dp[i][0] = true;
       }

       if(nums[0] <= sum ){
           dp[0][nums[0]] == true;
       }

       for( int ind = 1; ind < n; ind++ ){
           for( int target = 1; target <= sum; target++ ){

               bool nottake = dp[ind-1][target];

               bool take = false;
               if( nums[ind] <= target ){
                   take = dp[ind-1][target-nums[ind]];
               }

               dp[ind][target] = ( nottake | take );
           }
       }

       return dp[n-1][sum];

    }
};