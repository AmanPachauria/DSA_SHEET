// Solution 1

#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish) {
      vector<pair<int,int>> vp;
      for( int i = 0; i < start.size(); i++ ){
             vp.push_back({start[i],finish[i]});
      }

      sort(vp.begin(), vp.end());

      pair<int,int> temp = {vp[0].first, vp[0].second};
      int ans = 1;
      for( int i = 1; i < start.size(); i++ ){
            if(vp[i].first>=temp.second){
                ans++;
                temp = {vp[i].first, vp[i].second};
            }
            else if(vp[i].first>=temp.first && vp[i].second<=temp.second){
                temp = {vp[i].first, vp[i].second};
            }
            
      }

      return ans;
}


// Solution 2

#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish) {
      vector<pair<int,int>> vp;
      for( int i = 0; i < start.size(); i++ ){
             vp.push_back({start[i],finish[i]});
      }

      sort(vp.begin(), vp.end());

      int temp = vp[0].second;
      int ans = 1;
      for( int i = 1; i < start.size(); i++ ){
            if(vp[i].first>=temp){
                ans++;
                temp = vp[i].second;
            }
            else if(vp[i].first<=temp && vp[i].second<=temp){
                temp = vp[i].second;
            }
            
      }

      return ans;
}