// Solution 1 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) return 0;

         sort(nums.begin(), nums.end());
         int ans = 1, cnt = 1;
         for( int i = 1; i < nums.size(); i++ ){
               if(nums[i]==nums[i-1]) continue;
               if(nums[i]-nums[i-1]==1){
                   cnt++;
               }
               else{
                   ans = max(ans,cnt);
                   cnt = 1;
               }
         }

         return max(cnt,ans);
    }
};


// Solution 2

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
          
          unordered_set<int> st;
          for( int i = 0; i < nums.size(); i++ ) st.insert(nums[i]);
          int ans = 0;
          
          for( int i = 0; i<nums.size(); i++ ){
                int num = nums[i];
                 if(st.find(num-1)==st.end()){
                     int cnt = 1;
                     while(st.find(num+1)!=st.end()){
                         cnt++;
                         num++;
                     }
                     ans = max(ans,cnt);
                 }
          }

          return ans;
    }
};