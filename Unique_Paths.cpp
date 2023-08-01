// Solution 1

class Solution {
public:
    int uniquePaths(int m, int n) {
         
         vector<int> pre_vec(n,1);
         for( int i = 1; i < m; i++){
             vector<int> vec(n,1);
             for( int j = 1; j < n; j++ ){
                  vec[j] = pre_vec[j]+vec[j-1];
             }
             pre_vec = vec;
         }

         return pre_vec[n-1];
        
    }
};


// Solution 2

class Solution {
public:
    int countpath(int i, int j , int m, int n){
         
         if(i==n-1 && j==m-1) return 1;
         if(i>=n || j>=m) return 0;
         else return countpath(i+1,j,m,n)+countpath(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
         
        return countpath(0,0,m,n);
        
    }
};