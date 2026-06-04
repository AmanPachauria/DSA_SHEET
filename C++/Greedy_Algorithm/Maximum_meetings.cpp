int maximumMeetings(vector<int> &start, vector<int> &end)
{
     vector<pair<int,int>> vp;
     for( int i = 0; i < start.size(); i++ ){
         vp.push_back({start[i],end[i]});
     }

     sort(vp.begin(), vp.end());
     pair<int,int> tpair;
     tpair = {vp[0].first,vp[0].second};
     int ans = 1;
     for( int i = 1; i < vp.size(); i++ ){
          if(vp[i].first>=tpair.first && vp[i].second<=tpair.second){
              tpair = {vp[i].first, vp[i].second};
          }
          else if(vp[i].first>=tpair.first && vp[i].first<=tpair.second){
              continue;
          }
          else{
              ans++;
              tpair = {vp[i].first, vp[i].second};
          }
     }

     return ans;
}