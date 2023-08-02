// Solution 1

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> vp;
        for( int i = 0; i < nums.size(); i++ ) vp.push_back({nums[i],i});
        
        sort(vp.begin(),vp.end());
        sort(nums.begin(), nums.end());
        
        vector<int> vec;
        for( int i = 0; i < nums.size(); i++ ){
              int a = target-nums[i];

             auto it1 = lower_bound(nums.begin(),nums.end(),a);
             int ind = it1-nums.begin();
             if(ind<nums.size() && *it1==a && vp[i].second!=vp[ind].second){
                 vec.push_back(vp[i].second);
                 vec.push_back(vp[ind].second);
                 break;
             }
        }
        
        return vec;
    }
};


// Solution 2 usisng two ponter