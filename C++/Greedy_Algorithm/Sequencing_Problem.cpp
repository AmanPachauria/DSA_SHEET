#include <bits/stdc++.h> 
using namespace std;

bool compare(vector<int> &v1, vector<int> &v2){
    return (v1[2]>v2[2]);
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{     
      
      sort(jobs.begin(), jobs.end(), compare);
     
      int mx = 0;
      for( int i = 0; i < jobs.size(); i++ ){
            mx = max(mx, jobs[i][1]);
      }

      vector<int> rec(mx+1,-1);
      int ans1 = 0;
      int cnt = 0;

      for( int i = 0; i < jobs.size(); i++){
            int j = jobs[i][1];
            for(int k = j; k>0; k--){
                if(rec[k]==-1){
                    ans1 += jobs[i][2];
                    cnt++;
                    rec[k] = jobs[i][0];
                    break;
                }
            }
      }
    
      vector<int> ans;
      ans.push_back(cnt);
      ans.push_back(ans1);
      return ans;
     
}