#include <bits/stdc++.h> 

void merge(vector<long long> &vec, long long &ans, int low, int mid, int high){
         
         int left = low;
         int right = mid+1;
         vector<long long> vec1;
         while(left<=mid && right<=high){
             if(vec[left]>vec[right]){
                 vec1.push_back(vec[right]);
                 right++;
                 ans += (mid-left)+1;
             }
             else{
                 vec1.push_back(vec[left]);
                 left++;
             }
         }

         while(left<=mid){
             vec1.push_back(vec[left]);
             left++;
         }

         while(right<=high){
             vec1.push_back(vec[right]);
             right++;
         }
         
         for( int i = low; i<=high; i++ ){
             vec[i] = vec1[i-low];
         }
}

void sortarray(vector<long long> &vec,long long &ans, int low, int high ){
        
        if(low>=high) return;
        int mid = (low+high)/2;
        sortarray(vec, ans, low, mid);
        sortarray(vec, ans, mid+1, high);

        merge(vec, ans, low, mid, high);
}
long long getInversions(long long *arr, int n){
      long long ans = 0;  
      vector<long long> vec;
      for( int i = 0; i < n; i++ ){
          vec.push_back(arr[i]);
      }
      sortarray(vec, ans, 0, n-1);
      return ans;
}