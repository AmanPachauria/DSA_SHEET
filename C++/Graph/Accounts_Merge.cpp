class Solution {
 
 class Disjoint{
     public:
       vector<double> size;
       vector<int> parent;
       Disjoint(int n){
           size.resize(n, 0);
           parent.resize(n, 0);
           for( int i = 0; i < n; i++ ){
               size[i] = 1;
               parent[i] = i;
           }
       }
       
       int ParentU(int node){
           if(parent[node]==node) return node;
           return parent[node] = ParentU(parent[node]);
       }

       void UnionBySize(int u, int v){
            int p_u = ParentU(u);
            int p_v = ParentU(v);
            
            if(p_u==p_v) return;
            if(size[p_u]>size[p_v]){
                parent[p_v] = p_u;
                size[p_u] += size[p_v];
            }
            else{
                parent[p_u] = p_v;
                size[p_v] += size[p_u];
            }
       }
 };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> mp;
        int n = accounts.size();
        Disjoint ds(n);
        for( int i = 0; i < n; i++ ){
            for( int j = 1; j < accounts[i].size(); j++ ){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else{
                    ds.UnionBySize(i, mp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> vs(n);
        for(auto mail : mp){
            int node = ds.ParentU(mail.second);
            vs[node].push_back(mail.first);
        }

        vector<vector<string>> ans;
        for( int i = 0; i < n; i++ ){
            if(vs[i].size()==0) continue;

            sort(vs[i].begin(), vs[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto mail : vs[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};