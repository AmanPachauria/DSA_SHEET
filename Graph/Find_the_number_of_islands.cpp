# Solution 1

class Solution {
  public:
  
    void fillvisit(vector<vector<char>> grid, vector<vector<int>> &visit, int row, int col){
    
        queue<pair<int,int>> q;
        q.push({row, col});
        visit[row][col] = 1;
        
        int n = grid.size(), m = grid[0].size();
        
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            
            for( int i = -1; i <= 1; i++){
                for( int j = -1; j <= 1; j++ ){
                    int nrow = a+i;
                    int ncol = b+j;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                      && grid[nrow][ncol]=='1' && visit[nrow][ncol]==0){
                          visit[nrow][ncol] = 1;
                          q.push({nrow,ncol});
                      }
                }
            }
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visit(n, vector<int>(m,0));
        
        int ans = 0;
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                    if(grid[i][j]=='1' && !visit[i][j]){
                        ans++;
                        // cout<<i<<" "<<j<<"\n";
                        fillvisit(grid, visit, i, j);
                        // cout<<ans<<"\n";
                    }        
            }
        }
        
        return ans;
    }
};


# Solution 2

class Solution {
  public:
  
    void fillvisit(vector<vector<char>> grid, vector<vector<int>> &visit, int row, int col){
    
        if(row>=grid.size() || col>=grid[0].size() || col<0 || row<0){
            return;
        }
        
        visit[row][col] = 1;
        
        for(int i = -1; i <=1; i++){
            for( int j = -1; j <= 1; j++ ){
                if(row+i<grid.size() && row+i>=0 && col+j<grid[0].size() && col+j>=0 && visit[row+i][col+j]==0 && grid[row+i][col+j]=='1'){
                     visit[row][col] = 1;
                     fillvisit(grid, visit, row+i, col+j);   
                }
            }
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visit(n, vector<int>(m,0));
        
        int ans = 0;
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                    if(grid[i][j]=='1' && !visit[i][j]){
                        ans++;
                        // cout<<i<<" "<<j<<"\n";
                        fillvisit(grid, visit, i, j);
                        // cout<<ans<<"\n";
                    }        
            }
        }
        
        return ans;
    }
};