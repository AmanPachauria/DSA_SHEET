class Solution {

class Disjoint{ 
    public:
    vector<int> size, parent;
       Disjoint(int n){
           size.resize(n, 0);
           parent.resize(n, 0);
           for( int i = 0; i < n; i++ ){
               size[i] = 1;
               parent[i] = i;
           }
       }

       int ParentU(int u){
           if(parent[u] == u) return u;
           return parent[u] = ParentU(parent[u]);
       }

       void UniouBySize(int u, int v){
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

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
      Disjoint ds(n);
      
      int extra = 0;
      for( int i = 0; i < connections.size(); i++ ){
          int u = connections[i][0];
          int v = connections[i][1];

          if(ds.ParentU(u)==ds.ParentU(v)){
              extra++;
          }
          else{
              ds.UniouBySize(u, v);
          }
      }

      int cnt = 0;
      for( int i = 0; i < n; i++ ){
          if(ds.parent[i]==i){
              cnt++;
          }
      }

      int ans = cnt-1;
      if(extra>=ans) return ans;
      return -1;  
    }
};