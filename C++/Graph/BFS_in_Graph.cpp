vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> visit(n+1, 0);
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        visit[node] = 1;

        for( auto it : adj[node]){
            if(!visit[it]){
                visit[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;

}