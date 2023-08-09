// Solution 1

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = 0;
        int ans = 0;

        while(i<height.size()-1){
            int temp_mx = -1, temp_ind = -1;
            for(j = i+1; j < height.size(); j++){
                if(height[j]>temp_mx){
                    temp_mx = height[j];
                    temp_ind = j;
                }
                if(height[j]>=height[i]){
                    for(int k = i+1; k < j; k++ ){
                         ans += height[i]-height[k];    
                    }
                    i = j;
                    temp_mx = -1;
                    temp_ind = -1;
                }
            }

            if(i<height.size()-1 && temp_ind>i){
                for(int k = temp_ind-1; k>i; k--){
                     ans += height[temp_ind]-height[k];
                }
                i = temp_ind;
            }
        }

        return ans;
    }
};




// Solution 2

class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size();
         vector<int> prefix(n),sufix(n);
         prefix[0] = height[0];
         for( int i = 1; i < n; i++ ){
             prefix[i] = max(prefix[i-1],height[i]);
         }

         sufix[n-1] = height[n-1];
         for( int i = n-2; i>=0; i--){
             sufix[i] = max(sufix[i+1], height[i]);
         }

         int ans = 0;
         for( int i = 0; i < n; i++ ){
             ans += min(sufix[i],prefix[i])-height[i];
         }
         return ans;
    }
};