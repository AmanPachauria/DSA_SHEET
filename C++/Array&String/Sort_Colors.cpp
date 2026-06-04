class Solution {
public:
    void sortColors(vector<int>& nums) {
         
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for( int i = 0; i < nums.size(); i++ ){
            if(nums[i]==0) cnt0++;
            else if(nums[i]==1) cnt1++;
            else cnt2++;
        }

        for( int i = 0; i < nums.size(); i++ ){
             if(cnt0>i) nums[i] = 0;
             else if(cnt0+cnt1>i) nums[i] = 1;
             else nums[i] = 2;
        }
    }
};