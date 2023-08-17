// Solution 1

class Solution {
public:

   bool checkattack(vector<string> vec, int row, int col){
            int row1 = row-1, col1 = col-1;
            int m = vec.size();
            while(row1>=0 && col1>=0){
                if(vec[row1][col1]=='Q') return false;
                row1--; col1--;
            }

            row1 = row; col1 = col-1;
            while(col1>=0){
                if(vec[row1][col1]=='Q') return false;
                col1--;
            }

            row1 = row+1; col1 = col-1;
            while(row1<m && col1>=0){
                if(vec[row1][col1]=='Q') return false;
                row1++; col1--;
            }

            return true;
   }
   
   void allway(vector<vector<string>> &ans, vector<string> &vec, int n, int col){
           if(col==n){
               ans.push_back(vec);
               return;
           }

           for( int i = 0; i < n; i++ ){
               if(checkattack(vec, i, col)){
                   vec[i][col] = 'Q';
                   allway(ans, vec, n, col+1);
                   vec[i][col] = '.';
               }
           }
   }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> vec;
        string s(n,'.');
        for( int i = 0; i < n; i++ ){
            vec.push_back(s);
        }
        allway(ans, vec, n, 0);

        return ans;
        
    }
};


// Solution 2

class Solution {
public:

void solve(int col, int n, vector<vector<string>> &ans,vector<string> &temp, vector<int> &left, vector<int> &leftup, vector<int> &leftdown){
        
           if(col==n){
               ans.push_back(temp);
               return;
           }

           for( int row = 0; row<n; row++){
               if(left[row]==0 && leftdown[row+col]==0 && leftup[n-1+col-row]==0){
                     temp[row][col] = 'Q';
                     left[row] = 1;
                     leftdown[row+col] = 1;
                     leftup[n-1+col-row] = 1;
                     solve(col+1, n, ans, temp, left, leftup, leftdown);
                     temp[row][col] = '.';
                     left[row] = 0;
                     leftdown[row+col] = 0;
                     leftup[n-1+col-row] = 0;
               }
           }

           return;

   }

 

    vector<vector<string>> solveNQueens(int n) {


        vector<vector<string>> ans;
        vector<string> temp;
        string s(n,'.');
        for( int i = 0; i < n; i++ ){
            temp.push_back(s);
        }

        vector<int> left(n,0), leftup(2*n,0), leftdown(2*n,0);

        solve(0, n, ans,temp, left, leftup, leftdown);

        return ans;
        
    }
};