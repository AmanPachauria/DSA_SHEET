// Solution 1

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        int a = 1;
        for( int i = 1; i <= nums.size(); i++ ){
             a *= i;
        }

        for( int i = 0; i < a ; i++ ){
             next_permutation(nums.begin(), nums.end());
             ans.push_back(nums);
        }
        return ans;
    }
};

// Solution 2

class Solution {
public:
    void allpermutation(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, vector<bool> freq){
            if(ds.size()==nums.size()){
                 ans.push_back(ds);
                 return;
            }

            for( int i = 0; i < nums.size(); i++ ){
                   if(freq[i]==false){
                       freq[i] = true;
                       ds.push_back(nums[i]);
                       allpermutation(nums, ans, ds, freq);
                       ds.pop_back();
                       freq[i] = false;
                   }
            }
    }
    vector<vector<int>> permute(vector<int>& nums) {

       vector<vector<int>> ans;
       vector<int> ds;
       int n = nums.size();
       vector<bool> freq(n, false);
       allpermutation(nums, ans, ds, freq);

       return ans;
    }
};

// Solution 3

class Solution {
public:
     
    void allpermutation(vector<int> &nums, vector<vector<int>> &ans, int ind){
             if(ind==nums.size()){
                 ans.push_back(nums);
             }

             for( int i = ind; i < nums.size(); i++ ){
                   swap(nums[i],nums[ind]);
                   allpermutation(nums, ans, ind+1);
                   swap(nums[i], nums[ind]);
             }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {

      vector<vector<int>> ans;
      allpermutation(nums, ans, 0);
      return ans;
    }
};