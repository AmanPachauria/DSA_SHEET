// Solution 1


class Solution {
public:

    int Fun1(int ind, vector<int> & nums, vector<int> & dp){
        if( ind == 0) return nums[ind];
        if( ind < 0) return 0;
        if( dp[ind] != -1 ) return dp[ind];

        int pick = nums[ind] + Fun1( ind-2, nums, dp);
        int notpick = 0 + Fun1( ind - 1, nums, dp);

        return dp[ind] = max( pick, notpick );
    }

    int Fun2( int ind, vector<int> & nums, vector<int> & dp){
    
        if( ind == 1 ) return nums[ind];
        if( ind < 1 ) return 0;
        if( dp[ind] != -1 ) return dp[ind];
        
        int pick = nums[ind] + Fun1( ind-2, nums, dp);
        int notpick = 0 + Fun1( ind - 1, nums, dp);
        
        return dp[ind] = max( pick, notpick );
    }

    int rob(vector<int>& nums) {
        
        if( nums.size()==1 ) return nums[0];
        int n = nums.size();
        vector<int> dp(n+1, -1);

        // last element not consider
        int ans1 = Fun1(n-2, nums, dp);

        for( int i = 0; i <= n; i++ ) dp[i] = -1;

        // First element not consider
        nums[0] = 0;
        int ans2 = Fun2(n-1, nums, dp);
       
        return max( ans1, ans2 );
    }
};


// Solution 2

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if( n == 1 ) return nums[0];
        vector<int> dp(n+1, 0);

        dp[1] = nums[1];
        
        for( int i = 2; i < n; i++ ){
            dp[i] = max( dp[i-2] + nums[i], dp[i-1]);
        }

        int ans1 = dp[n-1];

        for( int i = 0; i <= n; i++ ) dp[i] = 0;

        dp[0] = nums[0];
        dp[1] = max( nums[0], nums[1]);

        for( int i = 2; i < n-1; i++ ){
            dp[i] = max( dp[i-2] + nums[i], dp[i-1]);
        }

        int ans2 = dp[n-2];

        return max(ans1, ans2);

    }
};