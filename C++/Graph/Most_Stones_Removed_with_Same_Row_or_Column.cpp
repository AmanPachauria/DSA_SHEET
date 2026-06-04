class DisjointSet{
   public:
      vector<int> size, parent;
      DisjointSet(int n){
          size.resize(n+1, 0);
          parent.resize(n+1, 0);
          for( int i = 0; i <= n; i++ ){
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

          if(p_u == p_v) return;
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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int mxrow = INT_MIN, mxcol = INT_MIN;
        for( auto it : stones){
            mxrow = max(mxrow, it[0]);
            mxcol = max(mxcol, it[1]);
        }

        DisjointSet ds(mxrow + mxcol + 1);
        
        unordered_map<int,int> mp;
        for(auto it : stones){
            int row = it[0];
            int col = it[1];

            int newcol = col + mxrow + 1;

            ds.UnionBySize(row, newcol);
            mp[row] = 1;
            mp[newcol] = 1;
        }

        int cnt = 0;
        for( auto it : mp){
            if(it.first == ds.ParentU(it.first)){
                cnt++;
            }
        }

        return stones.size()-cnt;
    }
};