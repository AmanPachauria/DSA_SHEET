int minimumOperations(int n, int start, int end, vector<int> &a)
{    
     int mod = 1e3;
     queue<pair<int,int>> q;
     
     q.push({0, start});

     vector<int> step(mod, 1e9);
     step[start] = 0;

     while(!q.empty()){
         int stp = q.front().first;
         int node = q.front().second;
         q.pop();

         for(auto it : a){
             int node1 = (node * it) % mod;

             if( stp + 1 < step[node1] ){
                 step[node1] = stp + 1;
                 q.push({step[node1], node1});
             } 
         }
     }

     if(step[end]==1e9) return -1;
     return step[end];

}