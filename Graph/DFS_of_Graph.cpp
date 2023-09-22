class Solution {
     
  public:
  
    void finddfs(int node, vector<int> adj[], vector<int> &dfs, vector<int> &visit){
        visit[node] = 1;
        dfs.push_back(node);
        
        for( auto it : adj[node]){
            if(!visit[it]){
                finddfs(it, adj, dfs, visit);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int> dfs;
       vector<int> visit(V+1);
       int start = 0;
       finddfs(start, adj, dfs, visit);
       
       return dfs;
    }
};