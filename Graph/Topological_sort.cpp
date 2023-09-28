#include <bits/stdc++.h>

void dfs(int node, stack<int> &st, vector<int> &visit, vector<vector<int>> &adj){
      visit[node] = 1;

      for(auto it : adj[node]){
          if(!visit[it]){
              dfs(it, st, visit, adj);
          }
      }

      st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
     
     vector<int> visit(nodes);
     stack<int> st;
     vector<vector<int>> adj(nodes);
     for(int i = 0; i < edges; i++ ){
          adj[graph[i][0]].push_back(graph[i][1]);
     }

     for( int i = 0; i < nodes; i++ ){
         if(!visit[i]){
             dfs(i, st, visit, adj);
         }
     }

     vector<int> ans;
     while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
     }

     return ans;
}
