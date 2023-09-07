class Solution {
public:
    string countAndSay(int n) {
      string ans = "1";
      n = n-1;
      while(n--){
         vector<pair<int,char>> vp;
         int cnt = 1;
         char ch = ans[0];
         for( int i = 1; i < ans.size(); i++ ){
              if(ch!=ans[i]){
                vp.push_back({cnt,ch});
                ch = ans[i];
                cnt = 1;
              }
              else{
                cnt++;
              }
         }
         vp.push_back({cnt,ch});
         ans.erase();
         for( int i = 0; i < vp.size(); i++ ){
             char ch1 = vp[i].first + '0';
             ans += ch1;
             ans += vp[i].second;
         }
      } 

      return ans;
    }
};