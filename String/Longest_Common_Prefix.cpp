class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         
         string ans = "";
         sort(strs.begin(), strs.end());
         string f = strs[0], l = strs[strs.size()-1];
         for( int i = 0; i < min(f.size(),l.size()); i++ ){
             if(f[i]!=l[i]){
                 return ans;
             }
             ans += l[i];
         }

         return ans;
    }
};