#include <bits/stdc++.h>

void topodfs(int node, stack<int>&st, vector<int>&visit, vector<vector<pair<int,int>>> &adj){
       visit[node] = 1;

       for( auto it : adj[node]){
           if(!visit[it.first]){
              topodfs(it.first, st, visit, adj);
           }
       }

       st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
      vector<vector<pair<int,int>>> adj(n);
      for( int i = 0; i < m; i++ ){
          adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
      }
      
      vector<int> visit(n);
      stack<int> st;
      for( int i = 0; i < n; i++ ){
            if(!visit[i]){
                topodfs(i, st, visit, adj);
            }
      }

      vector<int> dist(n, INT_MAX);
      dist[0] = 0;
      
      while(!st.empty()){
          int node = st.top();
          st.pop();
          if(dist[node]==INT_MAX) continue;
          for( auto it : adj[node]){
                if(dist[node]+it.second < dist[it.first]){
                    dist[it.first] = dist[node]+it.second;
                }
          } 
      }

      for( int i = 0; i < n; i++ ){
          if(dist[i]==INT_MAX) dist[i] = -1;
      }

      return dist;

}
