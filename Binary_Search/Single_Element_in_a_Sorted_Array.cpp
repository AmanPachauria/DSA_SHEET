// Solution 1

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        if(nums.size()==1) return nums[0];

        int left = 0, right = nums.size()-1;
        while(left<=right){
           int mid = (left+right)/2;
           int a = -1, b = -1;
           if(mid-1>=0){
               a = nums[mid-1];
           }
           if(mid+1<nums.size()){
               b = nums[mid+1];
           }

           if(nums[mid]!=a && nums[mid]!=b){
               return nums[mid];
           }

           if((nums[mid]==a && mid%2==0) || (nums[mid]==b && mid%2==1) ) right = mid-1;
           else{ left = mid+1;}
        }

        return -1;
        
    }
};

// Solution 2

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int left = 0, right = nums.size()-2;
        while(left<=right){
           int mid = (left+right)/2;
           if(nums[mid]==nums[mid^1]){
               left = mid+1;
           }
           else{
               right = mid-1;
           }
        }

        return nums[left];
        
    }
};