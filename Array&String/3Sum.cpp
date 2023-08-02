class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         
         vector<vector<int>> mat;
         sort(nums.begin(), nums.end());
         for( int i = 0; i < nums.size(); i++ ){
             if(i!=0 && nums[i]==nums[i-1]) continue;
             
             int j = i+1, k = nums.size()-1;
             while(j<k){
                 
                 int sum = nums[i]+nums[j]+nums[k];
                 if(sum<0) j++;
                 else if(sum>0) k--;
                 else{
                     vector<int> vec = {nums[i], nums[j], nums[k]};
                     mat.push_back(vec);
                     j++; 
                     k--;
                     while(j<k && nums[j]==nums[j-1]) j++;
                     while(j<k && nums[k]==nums[k+1]) k--;
                 }
             }
         }
        
        return mat;
        
    }
};