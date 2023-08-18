// Solution 1

class Solution {
public:
  int search(vector<int> nums, int target) {
          
          int left = 0, right = nums.size()-1;
          while(left < right){
               int mid = left + (right-left)/2;
              if(nums[left]>nums[mid] || nums[right]>=nums[mid]){
                     right = mid;
               }
               else{
                   left = mid+1;
               }
          }
           
      //      cout<<left<<"\n";
          int rleft = left, rright = nums.size()-1;
           left = 0; right = rleft;
      //      if(rleft == 0) right = 0;
           
           int ans = -1;
      //      cout<<left<<" "<<right<<"\n";
           while(left<=right){
               int mid = left + (right-left)/2;
               if(nums[mid]==target) return mid;
               if(nums[mid]>target) right = mid-1;
               else{ left = mid+1;}
           }
           
           while(rleft<=rright){
                 int mid = rleft + (rright-rleft)/2;
                 if(nums[mid]==target) return mid;
                 if(nums[mid]>target) rright = mid-1;
                 else{ rleft = mid+1;}
           }

           

          return ans;
       
    }
};

// Solution 2

class Solution {
public:
  int search(vector<int> nums, int target) {
          
          int left = 0, right = nums.size()-1;
          while(left <= right){
               int mid = left + (right-left)/2;
               if(nums[mid]==target) return mid;

               if(nums[mid]>=nums[left]){
                     if(target>=nums[left] && target<=nums[mid]){
                           right = mid-1;
                     }
                     else{
                           left = mid+1;
                     }
                     
               }
               else{
                     if(nums[mid]<=target && nums[right]>=target){
                           left = mid+1;
                     }
                     else{
                           right = mid-1;
                     }
               }
              
          }
           
          return -1;
       
    }
};