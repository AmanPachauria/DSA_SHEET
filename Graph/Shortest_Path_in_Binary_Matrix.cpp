class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         
         
         if(grid[0][0]==1) return -1;
         int n = grid.size();
         if(grid[n-1][n-1]!=0) return -1;

         queue<pair<int,pair<int,int>>> q;
         q.push({1, {0,0}});

         while(!q.empty()){
             int ans = q.front().first;
             int row = q.front().second.first;
             int col = q.front().second.second;
             q.pop();
             if(row==n-1 && col==n-1){
                 return ans;
             }

             for( int i = -1; i <= 1; i++ ){
                 for( int j = -1; j <= 1; j++ ){
                     if(i==0 && j==0) continue;
                     int nrow = row+i;
                     int ncol = col+j;

                     if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0){
                         grid[nrow][ncol] = -1;
                         q.push({ans+1,{nrow, ncol}});
                     }
                 }
             }
         }

         return -1;
    }
};