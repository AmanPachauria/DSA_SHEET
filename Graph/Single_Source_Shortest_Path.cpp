vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {

     vector<vector<int>> adj(n);
     for( int i = 0; i < edges.size(); i++ ){
         adj[edges[i][0]].push_back(edges[i][1]);
         adj[edges[i][1]].push_back(edges[i][0]);
     }

     queue<pair<int,int>> q;
     q.push({src, 0});
     
     vector<int> dist(n, INT_MAX);
     dist[src] = 0;
     while(!q.empty()){
         int node = q.front().first;
         int distance = q.front().second;
         q.pop();

         for( auto it : adj[node]){
             if(dist[node]+1 < dist[it]){
                 dist[it] = dist[node] + 1;
                 q.push({it, dist[node]+1});
             }
         }
     }

     for( int i = 0; i < n; i++ ){
         if(dist[i]==INT_MAX) dist[i] = -1;
     }

     return dist;
}