// Solution 1

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> mat;
        set<vector<int>> st;
        for( int i = 0; i < nums.size(); i++ ){
            for( int j = i+1; j < nums.size(); j++ ){
                for(int k = j+1; k < nums.size(); k++){
                    long long a = (target*1.00) -((nums[i]*1.00)+(nums[j]*1.00)+(nums[k]*1.00))*1.00;

                    auto it1 = lower_bound(nums.begin(),nums.end(),a);
                    
                    int ind = it1-nums.begin();
                    
                    if(ind<nums.size() && a==nums[ind] && ind!=i && ind!=j && ind!=k){
                         vector<int> vec;
                         vec.push_back(nums[i]);
                         vec.push_back(nums[j]);
                         vec.push_back(nums[k]);
                         vec.push_back(nums[ind]);
                         sort(vec.begin(), vec.end());
                         int a1 = st.size();
                         st.insert(vec);
                         if(st.size()>a1) mat.push_back(vec);
                    }

                }
            }
        }
        

      return mat;
        
    }
};

// Solution 2


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
         vector<vector<int>> ans;
        for( int i = 0; i < nums.size(); i++ ){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1; j < nums.size(); j++){

                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1;
                int l = nums.size()-1;

                while(k<l){
                    long long sum = nums[i]*1.0+nums[j]*1.0+nums[k]*1.0+nums[l]*1.0;
                    if(target>sum) k++;
                    else if(target<sum) l--;
                    else{
                        vector<int> vec = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(vec);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }

       
        return ans;
    }
};