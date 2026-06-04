void finddfs(int node, vector<int> &dfs, vector<vector<int>> &list, vector<int> &visit){
      visit[node] = 1;
      dfs.push_back(node);
      for( auto it : list[node]){
          if(!visit[it]){
              finddfs(it, dfs, list, visit);
          }
      }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
     vector<vector<int>> list(V);
     for( int i = 0; i < E; i++ ){
           list[edges[i][0]].push_back(edges[i][1]);
           list[edges[i][1]].push_back(edges[i][0]);
     }

     vector<int> visit(V);
     vector<vector<int>> ans;
     for( int i = 0; i < V; i++ ){
         if(!visit[i]){
             vector<int> dfs;
             finddfs(i, dfs, list, visit);
             ans.push_back(dfs);
         }
     }

     return ans;
}