
class Disjoint{
   public:
     vector<int> size;
     vector<int> parent;

     Disjoint(int n){
         size.resize(n, 0);
         parent.resize(n, 0);
         for( int i = 0; i < n; i++ ){
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
         if(size[p_u]>size[p_v]){
             parent[p_v] = p_u;
             size[p_u] += size[p_v]; 
         }
         else{
             parent[p_u] = p_v;
             size[p_v] += size[p_u];
         }
     }
};

vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q)
{
    Disjoint ds(n*m);
    vector<vector<int>> grid(n, vector<int>(m, 0));
    int visit[n][m];
    memset(visit, 0, sizeof visit);
    
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};

    int cnt = 0;
    
    vector<int> ans;
    for( int i = 0; i < q; i++ ){
        
              auto it = queries[i];
              
              int row = it[0];
              int col = it[1];

              if(visit[row][col]==1){
                  ans.push_back(cnt);
                  continue;
              }
              
              visit[row][col] = 1;
              cnt++;
              grid[row][col] = 1;

              for( int i = 0; i < 4; i++ ){
                  int nrow = row + dr[i];
                  int ncol = col + dc[i];

                  if(nrow<n && ncol<m && nrow>=0 && ncol>=0){
                       
                       if(grid[nrow][ncol]==1){
                           int nnum = row*m + col;
                           int gnum = nrow*m + ncol;
                           if(ds.ParentU(nnum)!=ds.ParentU(gnum)){
                               cnt--;
                               ds.UnionBySize(nnum, gnum);
                           }
                       }
                  }
              }
        ans.push_back(cnt);
              
        
    }

    return ans;
}
