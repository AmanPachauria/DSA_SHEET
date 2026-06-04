// Solution 1

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
     vector<vector<pair<int, int>>> adj(vertices);
     for( int i = 0; i < edges; i++ ){
         adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
         adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
     }

     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

     vector<int> dist(vertices, INT_MAX);
     dist[source] = 0;

     pq.push({0, source});

     while(!pq.empty()){
         int node = pq.top().second;
         int dis = pq.top().first;
         pq.pop();
         
         for( auto it : adj[node]){
             int adjNode = it.first;
             int weight = it.second;
             
             if(dis + weight < dist[adjNode]){
                 dist[adjNode] = dis+weight;
                 pq.push({dist[adjNode], adjNode});
             }
         }
     }

     return dist;
}


// Solution 2 



vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
     vector<vector<pair<int, int>>> adj(vertices);
     for( int i = 0; i < edges; i++ ){
         adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
         adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
     }

     set<pair<int,int>> st;

     vector<int> dist(vertices, INT_MAX);
     dist[source] = 0;

     st.insert({0, source});

     while(!st.empty()){
         auto it = *(st.begin());
         int node = it.second;
         int wt = it.first;
         st.erase(it);

         for( auto it : adj[node]){
             int adjNode = it.first;
             int adjw = it.second;

             if(wt + adjw < dist[adjNode]){

                 if(dist[adjNode]!=INT_MAX){
                     st.erase({dist[adjNode], adjNode});
                 }

                  dist[adjNode] = wt + adjw;
                  st.insert({dist[adjNode], adjNode});
             }
         }
     }

     return dist;
}