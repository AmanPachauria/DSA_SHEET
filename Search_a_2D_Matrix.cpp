class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool flag = false;
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m-1;
        while( i>=0 && i<=n-1 && j>=0 && j<=m-1 ){
            if(target==matrix[i][j]){
                return true;
            }
            else if(target<matrix[i][j]){
                j--;
            }
            else{
                i++;
            }
        }
        return flag;
    }
};