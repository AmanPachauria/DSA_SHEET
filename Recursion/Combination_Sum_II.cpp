class Solution {
public:

    void alltarget(vector<int> &arr, vector<vector<int>> &ans, vector<int> temp, int target, int ind){
           
           if(target==0){
               ans.push_back(temp);
           }
           for( int i = ind; i < arr.size(); i++ ){
                  if(i!=ind && arr[i]==arr[i-1]) continue;
                  if(arr[i]>target) break;
                  temp.push_back(arr[i]);
                  alltarget(arr, ans, temp, target-arr[i], i+1);
                  temp.pop_back();
           }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          

          sort(candidates.begin(), candidates.end());
          vector<vector<int>> ans;
          vector<int> temp;
          alltarget(candidates, ans, temp, target, 0);

          return ans;   
    }
};