class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        set<int> rows, column;
        for( int  i = 0; i < n; i++ ){
             for( int j = 0; j < m; j++){
                 if(matrix[i][j] == 0){
                     rows.insert(i);
                     column.insert(j);
                 }
             }
        }

        for(auto it : rows){
            for( int j = 0; j < m; j++ ){
                matrix[it][j] = 0;
            }
        }

        for( auto it : column){
            for( int i = 0; i < n; i++ ){
                matrix[i][it] = 0;
            }
        }
        
    }
};