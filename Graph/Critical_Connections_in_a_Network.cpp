class Solution {
public:
    
    int time = 1;
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visit,
    vector<int> &tin, vector<int> &low, vector<vector<int>> &ans){
        visit[node] = 1;
        tin[node] = time;
        low[node] = time;
        time++;
        
        for( auto it : adj[node]){
            if(it==parent) continue;
            if(visit[it]==0){
               dfs(it, node, adj, visit, tin, low, ans);
               low[node] = min(low[it], low[node]);
               if(low[it]>tin[node]){
                   ans.push_back({it, node});
               }
            }
            else{
                low[node] = min(low[it], low[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
          
          vector<vector<int>> adj(n);
          for( int i = 0; i < connections.size(); i++ ){
               int a = connections[i][0];
               int b = connections[i][1];
               adj[a].push_back(b);
               adj[b].push_back(a);
          }

          vector<int> visit(n, 0), tin(n,0), low(n, 0);
          
          vector<vector<int>> ans;
          dfs(0, -1, adj, visit, tin, low, ans);

          return ans;
    }
};