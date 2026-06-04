class Disjoint{
   public:
     vector<int> size, parent;
     Disjoint(int n){
         size.resize(n, 0);
         parent.resize(n, 0);
         for(int i = 0; i < n; i++ ){
             size[i] = 1;
             parent[i] = i;
         }
     }

     int ParentU(int node){
         if(parent[node]==node) return node;
         return parent[node] = ParentU(parent[node]);
     }

     void UnionBySize(int u, int v){
         int p_u = ParentU(u);
         int p_v = ParentU(v);
         
         if(p_u==p_v) return;
         if(size[p_v]>size[p_u]){
             parent[p_u] = p_v;
             size[p_v] += size[p_u];
         }
         else{
             parent[p_v] = p_u;
             size[p_u] += size[p_v];
         }
     }
};
class Solution {
public:
    bool isvalid(int newr, int newc, int n){
        return (newr>=0 && newc>=0 && newr<n && newc<n);
    }

    int largestIsland(vector<vector<int>>& grid) {
          
          int n = grid.size();
          Disjoint ds(n*n);

          int dr[] = {1, 0, -1, 0};
          int dc[] = {0, 1, 0, -1};

          for( int row = 0; row<n; row++ ){
            for(int col = 0; col<n; col++ ){
                if(grid[row][col]==0) continue;
                for( int i = 0; i < 4; i++ ){
                    int newr = row + dr[i];
                    int newc = col + dc[i];

                    if(isvalid(newr, newc, n) && grid[newr][newc]==1){
                         int gnode = row * n + col;
                         int adjnode = newr * n + newc;
                         ds.UnionBySize(gnode, adjnode);
                    }
                }
            }
          }
           int ans = 0;
          for( int row = 0; row<n; row++){
              for(int col = 0; col<n; col++){
                  if(grid[row][col]==1) continue;
                  set<int> st;
                  for( int i = 0; i < 4; i++ ){
                      int newr = row + dr[i];
                      int newc = col + dc[i];

                      if( isvalid( newr, newc, n) && grid[newr][newc]==1){
                          int adjnode = newr * n + newc;
                          st.insert(ds.ParentU(adjnode));
                      }
                  }
                  int mx = 0;
                  for( auto it : st){
                     mx += ds.size[it];
                  }
                 
                  ans = max(ans, mx+1);
              }
          }
          
          for( int i = 0; i < n*n; i++ ){
              ans = max(ans, ds.size[ds.ParentU(i)]);
          }

          return ans;
    }
};