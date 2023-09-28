#include <bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
     
     vector<vector<int>> adj(nodes);
     for(int i = 0; i < edges; i++ ){
         adj[graph[i][0]].push_back(graph[i][1]);
     }
     
     vector<int> indegree(nodes);
     for(int i = 0; i < nodes; i++ ){
        for(auto it : adj[i]){
            indegree[it]++;
        }
     }

     queue<int> q;
     for(int i = 0; i<nodes; i++ ){
         if(indegree[i]==0) q.push(i);
     }
     
     vector<int> topo;
     while(!q.empty()){
         int node = q.front();
         q.pop();
         topo.push_back(node);

         for(auto it : adj[node]){
              indegree[it]--;
              if(indegree[it]==0) q.push(it);
         }
     }

     return topo;

}
