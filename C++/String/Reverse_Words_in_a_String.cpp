class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "", temp = "";

        for( int i = 0; i < s.size(); i++ ){
              if(s[i]!=' '){
                  temp += s[i];
              }
              else if(s[i]==' '){
                  if(ans!="" && temp!="") ans = temp + " " + ans;
                  if(ans=="") ans = temp;
                  temp = "";
              }
        }

        if(ans!="" && temp!="") ans = temp + " " + ans;
        if(ans=="") ans = temp;

        return ans;
        
    }
};