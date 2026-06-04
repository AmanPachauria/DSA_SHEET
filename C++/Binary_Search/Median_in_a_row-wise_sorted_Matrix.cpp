
int countlessthanmid(vector<int> &vec, int mid){
      int low = 0, high = vec.size()-1;
      while(low<=high){
          int mid1 = (low+high)/2;
          if(vec[mid1]<=mid){
              low = mid1+1;
          }
          else{
              high = mid1-1;
          }
      }

      return low;
}


int median(vector<vector<int>> &matrix, int m, int n) {
    
       int left = 1, right = 1e9;

       while(left<=right){
           int mid = (left+right)/2;
           int cnt = 0;
           for( int i = 0; i < m; i++ ){
               cnt += countlessthanmid(matrix[i], mid);
           }

           if(cnt<=(m*n)/2){
               left = mid+1;
           }
           else{
               right = mid-1;
           }
       }
}