// Solution 1

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         
         int n = heights.size();
         vector<int> left(n,0), right(n,n-1);
         stack<int> st;
         
         for( int i = 0; i < n; i++ ){
              while(!st.empty() && heights[st.top()]>=heights[i]){
                  st.pop();
              }
              if(!st.empty()) left[i] =st.top()+1;
              st.push(i);
         }
         
         while(!st.empty()) st.pop();

         for(int i = n-1; i>=0; i--){
              while(!st.empty() && heights[st.top()]>=heights[i]){
                  st.pop();
              }
              if(!st.empty()) right[i] = st.top()-1;
              st.push(i);
         }
        
         int ans = INT_MIN;
         for( int i = 0; i < n; i++ ){
             ans = max(ans, (right[i]-left[i]+1)*heights[i]);
         }
         return ans;
    }
};