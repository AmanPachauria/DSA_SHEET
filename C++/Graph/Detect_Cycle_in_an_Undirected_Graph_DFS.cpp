class Graph {

public:

    bool detect(int node, int parent, vector<int> &vis, vector<int> adj[]){
          vis[node] = 1;

          for( auto it : adj[node]){
              if(!vis[it]){
                 if(detect(it, node, vis, adj)==true){
                     return true;
                 }
              }
              else if(it!=parent){
                  return true;
              }
          }

          return false;
    }
  
    bool detectCycle(int V, vector<int> adj[]) {
        
        vector<int> vis(V, 0);
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, -1, vis, adj)==true) return true; 
            }
        }
        return false; 
    }
};