class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
          
         vector<vector<pair<int,int>>> adj(n);
         for( int i = 0; i < flights.size(); i++ ){
             adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
         }

          queue<pair<int,pair<int,int>>> pq;

          vector<int> dist(n, 1e9);
          dist[src] = 0;

          pq.push({0, {src, 0}});
          int ans = INT_MAX;
          while(!pq.empty()){
              auto it1 = pq.front();
              pq.pop();
              int dis = it1.first;
              int node = it1.second.first;
              int stop = it1.second.second;
              
              cout<<dis<<" "<<node<<" "<<stop<<"\n";
              if(node==dst && stop-1<=k){
                    ans = min(ans, dis);
              }

              for( auto it : adj[node]){
                  int nodeDis = it.second;
                  int node1 = it.first;

                  if(dis + nodeDis < dist[node1] && stop+1 <= k+1){
                      dist[node1] = dis + nodeDis;
                      pq.push({dist[node1], {node1, stop+1}});
                  }
              }
          }
          
          if(ans==INT_MAX) return -1;
          return ans;
    }
};