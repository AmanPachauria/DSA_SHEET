class Solution {
public:

   bool dfs(int node, vector<vector<int>> &graph, vector<int> &visit, vector<int> &pathvisit, vector<int> &check){
           visit[node] = 1;
           pathvisit[node] = 1;
        //    check[node] = 0;

           for( auto it : graph[node]){
               if(!visit[it]){
                   if(dfs(it, graph, visit, pathvisit, check)==true){
                    //    check[node] = 0;
                       return true;
                   }
               }
               else if(pathvisit[it]){
                    //    check[node] = 0;
                       return true;
                }
           }
           
           check[node] = 1;
           pathvisit[node] = 0;
           return false;
   }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          int v = graph.size();
          vector<int> visit(v);
          vector<int> pathvisit(v);
          vector<int> check(v);

          for( int i = 0; i < v; i++ ){
              if(!visit[i]){
                  dfs(i, graph, visit, pathvisit, check);
              }
          }

          vector<int> ans;
          for(int i = 0; i < v; i++ ){
              if(check[i]){
                  ans.push_back(i);
              }
          }

        return ans;
    }
};