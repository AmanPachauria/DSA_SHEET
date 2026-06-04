class Solution {
public:
    
    bool find(int node, vector<vector<int>> &graph, vector<int> &color){
          queue<int> q;
          q.push(node);
          color[node] = 0;

          while(!q.empty()){
              int temp = q.front();
              q.pop();

              for(auto it : graph[temp]){
                  if(it==temp) continue;
                  if(color[it]==-1){
                      q.push(it);
                      color[it] = 1-color[temp];
                  }
                  else if(color[it]==color[temp]){
                      return false;
                  }
              }
          }

          return true;

    }
   
    bool isBipartite(vector<vector<int>>& graph) {
         vector<int> color(graph.size(), -1);
         
        //  bool ans = true;
         for( int i = 0; i < graph.size(); i++ ){
             if(color[i]==-1){
                 if(find(i, graph, color)==false){
                     return false;
                 }
             }
         }

         return true;
    }
};