// Solution 1

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> adj(n, vector<int> (n, 1e9));
        for( int i = 0; i < edges.size(); i++ ){
            int a = edges[i][0];
            int b = edges[i][1];
            int d = edges[i][2];

            adj[a][b] = d;
            adj[b][a] = d;
        }   

        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                if(i==j) adj[i][j] = 0;
            }
        }

        for(int via = 0; via < n; via++){
            for( int i = 0; i < n; i++){
                for( int j = 0; j < n; j++){
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }

        vector<int> count(n);
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < n; j++ ){
                if(adj[i][j]!=1e9 && adj[i][j]<=distanceThreshold){
                    count[i]++;
                }
            }
        }
        int sum = INT_MAX;
        int ans = 0;
        for( int i = 0; i < n; i++ ){
            if(count[i]<=sum){
                sum = count[i];
                ans = i;
            }
        }
        return ans;
    }
};


// Solution 2 


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> adj(n, vector<int> (n, 1e9));
        for( int i = 0; i < edges.size(); i++ ){
            int a = edges[i][0];
            int b = edges[i][1];
            int d = edges[i][2];

            adj[a][b] = d;
            adj[b][a] = d;
        }   

        for( int i = 0; i < n; i++ ){
            if(i==i) adj[i][i] = 0;
        }

        for(int via = 0; via < n; via++){
            for( int i = 0; i < n; i++){
                for( int j = 0; j < n; j++){
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }

        int cnt = INT_MAX;
        int ans = -1;
        for( int i = 0; i < n; i++ ){
            int cntt = 0;
            for( int j = 0; j < n; j++ ){
                if(adj[i][j]<=distanceThreshold){
                    cntt++;
                }
            }
            
            if(cnt>=cntt){
                cnt = cntt;
                ans = i;
            }
        }
        
        return ans;
    }
};