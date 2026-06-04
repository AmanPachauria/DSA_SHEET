// #include <bist/stdc++.h>
// using namespace std;
#include<vector>
#include<set>
// #include<pair>

void dfs(int row, int col, vector<vector<int>> &visit, int** arr,
 vector<pair<int,int>> &ans, int urow, int ucol){
    if(row<0 || col<0 || row>=visit.size() || col>=visit[0].size() 
    || visit[row][col]==1 || arr[row][col]==0){
        return;
    }

    ans.push_back({row-urow, col-ucol});
    visit[row][col] = 1;

    dfs(row, col+1, visit, arr, ans, urow, ucol);
    dfs(row+1, col, visit, arr, ans, urow, ucol);
    dfs(row, col-1, visit, arr, ans, urow, ucol);
    dfs(row-1, col, visit, arr, ans, urow, ucol);
}

int distinctIslands(int** arr, int n, int m)
{
    vector<vector<int>> visit(n, vector<int>(m,0));
        // int visit[n][m];
        
        set<vector<pair<int,int>>> sv;
        for( int i = 0; i < n; i++ ){
        for( int j = 0; j < m; j++ ){
          if (visit[i][j] == 0 && arr[i][j]==1) {

            vector<pair<int, int>> ans;
            dfs(i, j, visit, arr, ans, i, j);
                sv.insert(ans);
            }
        }


    }

    return sv.size();
}