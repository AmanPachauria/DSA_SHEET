class Solution {
public:

    void alltarget(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int target, int ind){
          if(ind == arr.size()){
              if(target==0){
                  ans.push_back(temp);
              }
              return;
          }

          if(arr[ind]<=target){
              temp.push_back(arr[ind]);
              alltarget(arr, ans, temp, target-arr[ind], ind);
              temp.pop_back();
          }
          alltarget(arr, ans, temp, target, ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
           vector<vector<int>> ans;
           vector<int> temp;
           alltarget(candidates, ans, temp, target, 0);

           return ans;
    }
};