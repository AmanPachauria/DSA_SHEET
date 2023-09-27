class Solution {
public:

    bool dfs(int node, vector<vector<int>> &adj, vector<int>&visit, vector<int> &pathvisit){
        visit[node] = 1;
        pathvisit[node] = 1;

        for(auto it : adj[node]){
            if(!visit[it]){
                if((dfs(it, adj, visit, pathvisit))==false){
                    return false;
                }
            }
            else if(pathvisit[it]){
                return false;
            }
        }
        
        pathvisit[node] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          int n = numCourses;
          vector<vector<int>> adj(n);
          vector<int> visit(n,0);
          vector<int> pathvisit(n,0);

          for( int i = 0; i < prerequisites.size(); i++ ){
              adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
          }
          
          for( int i = 0; i < n; i++ ){
              if(!visit[i]){
                  if(dfs(i, adj, visit, pathvisit)==false){
                      return false;
                  };
              }
          }

          return true;
    }
};