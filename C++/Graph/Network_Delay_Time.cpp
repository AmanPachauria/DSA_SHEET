class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for( int i = 0; i < times.size(); i++ ){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int,int>, 
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        pq.push({0, k});

        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for( auto it : adj[node]){
                int adjNode = it.first;
                int adjtime = it.second;

                if(time + adjtime < dist[adjNode]){
                    dist[adjNode] = time + adjtime;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
       
       int ans = 0;
       for( int i = 1; i < n+1; i++ ){
           if(dist[i]==1e9) return -1;
           ans = max(ans, dist[i]);
       }

       return ans;
    }
};