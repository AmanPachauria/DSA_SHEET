// Solution 1


class Solution {
public:

    int Fun(int ind, vector<int> &nums, vector<int> &dp){

        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
       
        int pick = nums[ind] + Fun(ind-2, nums, dp); 
        int notpick = 0 + Fun(ind-1, nums, dp);

        return dp[ind] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return Fun(nums.size()-1, nums, dp);
    }
};


// Solution 2

class Solution {
public:

    int rob(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];

        vector<int> dp(nums.size()+1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for( int i = 2; i < nums.size(); i++ ){
            dp[i] = max( dp[i-2] + nums[i], dp[i-1]);
        }

        return dp[nums.size()-1];
    }
};