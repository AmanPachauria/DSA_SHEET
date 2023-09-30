class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
          priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;

         int n = heights.size(), m = heights[0].size();
         pq.push({0, {0,0}});

         vector<vector<int>> visit(n, vector<int>(m, 1e9));
         visit[0][0] = 0;

         int delta[] = {1, 0, -1, 0};
         int deltab[] = {0, 1, 0, -1};

         while(!pq.empty()){
             auto it = pq.top();
             int diff = it.first;
             int row = it.second.first;
             int col = it.second.second;
             pq.pop();

             if(row==n-1 && col==m-1){
                 return diff;
             }
             for( int i = 0; i < 4; i++ ){
                 int nrow = row + delta[i];
                 int ncol = col + deltab[i];
                 
                 if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                       int newdiff = max(abs(heights[row][col] - heights[nrow][ncol]), diff);

                        if(newdiff < visit[nrow][ncol]){
                            visit[nrow][ncol] = newdiff;
                            pq.push({newdiff,{nrow,ncol}});
                        }
                 }
             }
         }

         return 0;
    }
};