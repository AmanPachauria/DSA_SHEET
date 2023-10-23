// Solution 1 


class Solution {
public:

    int Fun( int ind, int target, vector<int> &nums, vector<vector<int>> &dp ){

        if( ind == 0 ){
            if( target == 0 && nums[0] == 0 ) return 2;
            else if( target == 0 || target == nums[0] ) return 1;
            else return 0;
        }

        if( dp[ind][target] != -1 ) return dp[ind][target];

        int nottake = Fun( ind - 1, target, nums, dp );
        int take = 0;
        if( nums[ind] <= target ) {
            take = Fun( ind - 1, target - nums[ind], nums, dp );
        }

        return dp[ind][target] = ( nottake + take );
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int totalsum = 0;
        for( int i = 0; i < n; i++ ){
            totalsum += nums[i];
        }

        if( totalsum - target < 0  || (totalsum - target) % 2 ) return 0;

        int newtarget = ( totalsum - target ) / 2;

        vector<vector<int>> dp( n, vector<int> (newtarget+1, -1 ));

        return Fun( n-1, newtarget, nums, dp );
    }
};


// Solution 2 


class Solution {
public:

    int Findways( vector<int> &nums, int target, int n){
        
        vector<vector<int>> dp( n, vector<int> (target+1, 0));

        if( nums[0] == 0 ){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
        }

        if( nums[0] != 0 && nums[0] <= target ){
            dp[0][nums[0]] = 1;
        }


        for( int ind = 1; ind < n; ind++ ){
            for( int tar = 0; tar <= target; tar++ ){

                int nottake = dp[ind-1][tar];
                int take = 0;
                if( nums[ind] <= tar ){
                    take = dp[ind-1][tar-nums[ind]];
                }

                dp[ind][tar] = nottake + take;
            }
        }

        return dp[n-1][target];
        
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int totalsum = 0;
        for( int i = 0; i < n; i++ ){
            totalsum += nums[i];
        }

        if( totalsum - target < 0  || (totalsum - target) % 2 ) return 0;

        int newtarget = ( totalsum - target ) / 2;

        return Findways(nums, newtarget, n);
    }
};