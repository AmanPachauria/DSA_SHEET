class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n =  matrix.size();
        vector<vector<int>> matrix1;

        for( int j = 0; j < n; j++ ){
            vector<int> vec;
            for( int i = 0; i < n; i++){
               vec.push_back(matrix[i][j]);
            }
            reverse(vec.begin(), vec.end());
            matrix1.push_back(vec);
        }

        matrix = matrix1;
        
    }
};