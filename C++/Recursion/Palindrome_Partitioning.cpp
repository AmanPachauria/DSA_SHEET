class Solution {
public:

    bool ispalindrome(string &s, int start, int end){
           while(start<=end){
               if(s[start++]!=s[end--]) return false;
           }
           return true;
    }

    void substring(vector<vector<string>> &ans, vector<string> &temp, string &s, int ind){
          if(ind==s.size()){
              ans.push_back(temp);
              return;
          }

          for( int i = ind; i < s.size(); i++ ){
                if(ispalindrome(s, ind, i)){
                    temp.push_back(s.substr(ind, i-ind+1));
                    substring(ans, temp, s, i+1);
                    temp.pop_back();
                }
          }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> temp;
        substring(ans, temp, s, 0);

        return ans;
        
    }
};