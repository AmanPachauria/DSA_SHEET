class Solution {
public:

    int countPaths(int n, vector<vector<int>>& roads) {
         
         int mod = 1e9+7;
         vector<vector<pair<int,int>>> adj(n);
         for( int i = 0; i < roads.size(); i++ ){
              adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
              adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
         }

         priority_queue<pair<long long,int>,
         vector<pair<long long,int>>,
         greater<pair<long long,int>>> pq;

         vector<long long> dist(n, LLONG_MAX), ways(n, 0);
         dist[0] = 0;
         ways[0] = 1;

         pq.push({0, 0});
         while(!pq.empty()){
             long long dst = pq.top().first;
             int node = pq.top().second;
             pq.pop();

             for(auto it : adj[node]){
                 long long adjdst = it.second;
                 int adjnode = it.first;

                 if( dst + adjdst < dist[adjnode]){
                     dist[adjnode] = dst + adjdst;
                     ways[adjnode] = ways[node];
                     pq.push({dist[adjnode], adjnode});
                 }
                 else if( dst + adjdst == dist[adjnode]){
                     ways[adjnode] = (ways[node] + ways[adjnode]) % mod;
                 }
             }
         }

         return ways[n-1]%mod;
    }
};