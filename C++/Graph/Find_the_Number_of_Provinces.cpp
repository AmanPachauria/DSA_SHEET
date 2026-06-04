#  Solution 1

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<int> visit(n);
    int ans = 0;
    queue<int> q;
    for(int i = 0; i < n; i++ ){
        if(!visit[i]){
            ans++;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                visit[node] = 1;
                q.pop();
                for( int j = 0; j < n; j++ ){
                    if(roads[node][j]==1 && visit[j]==0){
                        q.push(j);
                    }
                }
            }
        }
    }
    return ans;
}






# Solution 2


void finddfs(int node, vector<vector<int>> &list, vector<int> &visit){
    visit[node] = 1;
    for( auto it : list[node]){
        if(!visit[it]){
            finddfs(it, list, visit);
        }
    }
}
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<vector<int>> list(n);

    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            if(roads[i][j]==1 && i!=j){
                list[i].push_back(j);
                list[j].push_back(i);
            }
        }
    }
    
    int ans = 0;
    vector<int> visit(n+1, 0);
    for( int i = 0; i < n; i++ ){
        if(!visit[i]){
            ans++;
            finddfs(i, list, visit);
        }
    }
    // cout<<ans<<"\n";

    return ans;
}