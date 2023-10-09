// Solution 1

#include <bits/stdc++.h>

int ParentU(int u, vector<int> &parent){
	if(parent[u]==u) return u;
	return parent[u] = ParentU(parent[u], parent);
}

void unionBySize(int u, int v, vector<int> &size, vector<int> &parent){
	 
	 int p_u = ParentU(u, parent);
	 int p_v = ParentU(v, parent);

	 if(size[p_u]>size[p_v]){
		 parent[p_v] = p_u;
		 size[p_u] += size[p_v];
	 }
	 else{
		 parent[p_u] = p_v;
		 size[p_v] += size[p_u];
	 }
}

int kruskalMST(int n, vector<vector<int>> &edges)
{
	vector<int> size(n+1), parent(n+1);
	for( int i = 0; i <= n; i++ ){
		parent[i] = i;
		size[i] = 1;
	}

	vector<pair<int, pair<int,int>>> edg;
	for( int i = 0; i < edges.size(); i++ ){
		int a = edges[i][0];
		int b = edges[i][1];
		int c = edges[i][2];

		edg.push_back({c, {a, b}});
	}

	sort(edg.begin(), edg.end());

	int sum = 0;

	for( int i = 0; i < edg.size(); i++ ){
		int u = edg[i].second.first;
		int v = edg[i].second.second;

		if(ParentU(u, parent) != ParentU(v, parent)){
			sum += edg[i].first;
			unionBySize(u, v, size, parent);
		}
	}

	return sum;
}



// Solution 2

#include <bits/stdc++.h>

class Disjoint{
  vector<int> size, parent;

  public :
     Disjoint(int n){
		 size.resize(n+1, 0);
		 parent.resize(n+1, 1);

		 for( int i = 0; i <= n; i++ ){
			 size[i] = 1;
			 parent[i] = i;
		 }
	 }

	 int ParentU(int u){
		 if(parent[u]==u){
			 return u;
		 }
		 return parent[u] = ParentU(parent[u]);
	 }

	 void UnionBySize(int u, int v){
		 int p_u = ParentU(u);
		 int p_v = ParentU(v);
         
		 if(size[p_u]>size[p_v]){
			 parent[p_v] = p_u;
			 size[p_u] += p_v;
		 }
		 else{
			 parent[p_u] = p_v;
			 size[p_v] += p_u;
		 }

	 }
};


int kruskalMST(int n, vector<vector<int>> &edges)
{
	Disjoint ds(n);
	vector<pair<int, pair<int,int>>> edg;
	for( int i = 0; i < edges.size(); i++ ){
		int a = edges[i][0];
		int b = edges[i][1];
		int c = edges[i][2];

		edg.push_back({c, {a, b}});
	}

	sort(edg.begin(), edg.end());

	int sum = 0;

	for( int i = 0; i < edg.size(); i++ ){
		int u = edg[i].second.first;
		int v = edg[i].second.second;

		if(ds.ParentU(u) != ds.ParentU(v)){
			sum += edg[i].first;
			ds.UnionBySize(u, v);
		}
	}

	return sum;
}
