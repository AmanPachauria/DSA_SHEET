#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
     
     vector<int> left(n,-1), right(n,n);
     stack<int> st;
     for( int i = 0; i< n; i++ ){
         while(!st.empty() && a[st.top()]>=a[i]){
             st.pop();
         }
         if(!st.empty()) left[i] = st.top();
         st.push(i);
     }

     while(!st.empty()) st.pop();

     for( int i = n-1; i>=0; i--){
         while(!st.empty() && a[st.top()]>=a[i]){
             st.pop();
         }
         if(!st.empty()) right[i] = st.top();
         st.push(i);
     }
     
     int mn = -(1e9+1);
     vector<int> ans(n, mn);
     for( int i = 0; i < n; i++ ){
         int window = right[i]-left[i]-1;
         ans[window-1] = max(ans[window-1], a[i]);
     }

     int mx = ans[n-1];
     for( int i = n-1; i>=0; i--){
         mx = max(mx, ans[i]);
         ans[i] = mx;
     }

     return ans;
}