
bool dfs(int node, vector<int> &pathvisit, vector<int>&visit, vector<vector<int>>&adj){
	visit[node] = 1;
	pathvisit[node] = 1;

	for( auto it : adj[node]){
		if(!visit[it]){
			if(dfs(it, pathvisit, visit, adj)==true){
				return true;
			}
		}
		else if(pathvisit[it]){
			return true;
		}
	}
    
	pathvisit[node] = 0;
	return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<vector<int>> adj(v);
	vector<int> visit(v);
	vector<int> pathvisit(v);

	for( int i = 0; i < e; i++ ){
		adj[edges[i][0]].push_back(edges[i][1]);
	}

	for( int i = 0; i < v; i++ ){
		if(!visit[i]){
			if(dfs(i, visit, pathvisit, adj) == true){
				return true;
			}
		}
	}

	return false;
}
