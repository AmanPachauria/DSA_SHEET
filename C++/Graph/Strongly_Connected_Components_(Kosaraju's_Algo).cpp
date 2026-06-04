class Solution
{
	public:
	
	void FirstDfs(int node, vector<vector<int>> &adj, vector<int> &visit, stack<int> &st){
	    visit[node] = 1;
	    
	    for( auto it : adj[node]){
	        if(!visit[it]){
	           FirstDfs(it, adj, visit, st);    
	        }
	        
	    }
	    
	    st.push(node);
	}
	
	void SecondDfs(int node, vector<vector<int>> &newadj, vector<int> &visit){
	    visit[node] = 1;
	    
	    for( auto it : newadj[node]){
	        if(!visit[it]){
	           SecondDfs(it, newadj, visit);    
	        }
	        
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> visit(V, 0);
        stack<int> st;
        
        for(int i = 0; i < V; i++ ){
            if(!visit[i]){
                FirstDfs(i, adj, visit, st);
            }
        }
        
        
        
        vector<vector<int>> newadj(V);
        for( int i = 0; i < V; i++ ){
            visit[i] = 0;
            for( auto it : adj[i]){
                newadj[it].push_back(i);
            }
        }
        
      
        int ans = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visit[node]){
                ans++;
                SecondDfs(node, newadj, visit);
            }
        }
        return ans;
    }
};