class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visit(n, vector<int>(m,0));
        vector<vector<int>> dis(n, vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>> q;

        for( int i = 0; i < n; i++ ){
            for(int j = 0; j < m; j++ ){
                if(mat[i][j]==0){
                    q.push({{i,j}, 0});
                    visit[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
         while(!q.empty()){
             auto it = q.front();
             int row = it.first.first;
             int col = it.first.second;
             int step = it.second;

             q.pop();
             dis[row][col] = step;

             for( int i = 0; i < 4; i++){
                 int nrow = row + delrow[i];
                 int ncol = col + delcol[i];
                 
                 if(nrow>=0 && ncol>=0 && nrow<mat.size() &&
                  ncol<mat[0].size() && visit[nrow][ncol]==0){
                     visit[nrow][ncol] = 1;
                     q.push({{nrow,ncol}, step+1});

                 }
             }
             
         }

        return dis;
    }
};