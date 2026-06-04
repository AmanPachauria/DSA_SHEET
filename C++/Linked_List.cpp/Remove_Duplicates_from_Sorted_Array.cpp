// Solution 1

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
         vector<int> v;
         v.push_back(nums[0]);
         for( int i = 1; i< nums.size(); i++ ){
              if(v.back()!=nums[i]) v.push_back(nums[i]);
         }

         for( int i = 0; i < v.size(); i++ ){
             nums[i] = v[i];
         }

         return v.size();
    }
};


// Solution 2

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0, j = 0;
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
            }

            j++;
        }

        return i+1;   
       
    }
};