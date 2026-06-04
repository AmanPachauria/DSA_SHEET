#include <bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
      
     vector<vector<int>> adj(n+1);
     for(int i = 0; i < edges.size(); i++ ){
         adj[edges[i].first].push_back(edges[i].second);
     }

     vector<int> indegree(n+1);
     for( int i = 1; i <= n; i++ ){
        for(auto it : adj[i]){
            indegree[it]++;
        }
     }

     queue<int> q;
     for( int i = 1; i <= n; i++ ){
       if(indegree[i]==0){
          q.push(i);
       }
     }

     int cnt = 0;
     while(!q.empty()){
         int node = q.front();
         q.pop();
         cnt++;

         for( auto it : adj[node]){
             indegree[it]--;
             if(indegree[it]==0) q.push(it);
         }
     }

     return (n!=cnt);
}