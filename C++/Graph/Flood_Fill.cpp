class Solution {
public:
    
    void fillImage(vector<vector<int>>&image, vector<vector<int>>&visit, int row, int col, int precolor, int newcolor){
        if(row<0 || col<0 || row>=image.size() || col>=image[0].size() ||
        visit[row][col]==1 || image[row][col]!=precolor){
            return;
        }
        visit[row][col] = 1;
        image[row][col] = newcolor;
        
        fillImage(image, visit, row-1, col, precolor, newcolor);
        fillImage(image, visit, row+1, col, precolor, newcolor);
        fillImage(image, visit, row, col-1, precolor, newcolor);
        fillImage(image, visit, row, col+1, precolor, newcolor);
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int n = image.size(), m = image[0].size();
       vector<vector<int>> visit(n, vector<int>(m,0));

       fillImage(image, visit, sr, sc, image[sr][sc], color);
       return image;
    }
};