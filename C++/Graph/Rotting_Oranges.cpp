class Solution {
public:
    void MakeRotten(vector<vector<int>> &grid, vector<vector<int>> &visit, queue<pair<int,int>> &q, int &ans){
         
         int n = grid.size(), m = grid[0].size();
         while(!q.empty()){
             int cnt = 0;
             int size = q.size();
              for( int i = 0; i < size; i++ ){
                  int a = q.front().first;
                  int b = q.front().second;
                  q.pop();
                  if(a>=0 && b>=0 && a<n && b<m && grid[a][b]==1 && visit[a][b]==0){
                      cnt = 1;
                      grid[a][b] = 2;
                      visit[a][b] = 1;
                      q.push({a-1, b});
                      q.push({a+1, b});
                      q.push({a, b-1});
                      q.push({a, b+1});
                  }
              }
              if(cnt == 1) ans++;


         }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        
        queue<pair<int,int>> q;
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m;j++ ){
                if(grid[i][j]==2){
                    grid[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
       
       int ans = 0;
       MakeRotten(grid, visit, q, ans);
       for( int i = 0; i < n; i++ ){
           for( int j = 0; j < m; j++ ){
               if(grid[i][j] == 1){
                   return -1;
               }
           }
       }
       if(ans==0) return ans;
       return ans-1;
        
    }
};