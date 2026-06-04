// Solution 1

class Solution {
public:
    
    void allsubset(vector<int> &nums, set<vector<int>> &st, vector<int> ans, int n, int pos){
            if(pos==n){
                sort(ans.begin(), ans.end());
                st.insert(ans);
                return;
            }
            
            ans.push_back(nums[pos]);
            allsubset(nums, st, ans, n, pos+1);
            ans.pop_back();
            allsubset(nums, st, ans, n, pos+1);
    }
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         set<vector<int>> st;
         vector<int> ans;
         allsubset(nums, st, ans, nums.size(), 0);
         vector<vector<int>> mat;
         for( auto it : st) mat.push_back(it);
         return mat;   
    }
};


// Solution 2

class Solution {
public:
    
    void allsubset(vector<int> &nums, vector<vector<int>> &mat, vector<int> &ans, int n, int pos){
           
            mat.push_back(ans);
           for( int i = pos; i<n; i++ ){
               if(i!=pos && nums[i]==nums[i-1]) continue;
               ans.push_back(nums[i]);
               allsubset(nums, mat, ans, n, i+1);
               ans.pop_back();
           }
    }
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> mat;
         vector<int> ans;
         sort(nums.begin(), nums.end());
         allsubset(nums, mat, ans, nums.size(), 0);
         
         return mat;   
    }
};