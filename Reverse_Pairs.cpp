class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high){
           
           int left = low;
           int right = mid+1;
           vector<int> vec;

           while(left<=mid && right<=high){
               if(nums[left]<=nums[right]){
                   vec.push_back(nums[left]);
                   left++;
               }
               else{
                   vec.push_back(nums[right]);
                   right++;
               }
           }

           while(left<=mid){
               vec.push_back(nums[left]);
               left++;
           }
           while(right<=high){
               vec.push_back(nums[right]);
               right++;
           }
           
           for( int i = low; i<=high; i++ ){
               nums[i] = vec[i-low];
           }
    }

    void countans(vector<int> &nums, int &ans, int low, int mid, int high){
           
              int left = low;
              int right = mid+1;
              while(left<=mid && right<=high){
                  long long a = nums[left], b = 2.00*nums[right];
                  if(a>b){
                      ans += (mid-left)+1;
                      right++;
                  }
                  else{
                      left++;
                  }
              }
    }
    void sortarray(vector<int> &nums, int &ans, int low, int high){
         
         if(low>=high) return;

         int mid = (low+high)/2;
         sortarray(nums, ans, low, mid);
         sortarray(nums, ans, mid+1, high);

         countans(nums, ans, low, mid, high);

         merge(nums, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {

        int ans = 0;
        sortarray(nums, ans, 0, nums.size()-1);

        return ans;
        
    }
};