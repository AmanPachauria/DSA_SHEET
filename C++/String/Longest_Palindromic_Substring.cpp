class Solution {
public:
    void addhash(string s, string &str){
        str += '#';
        for( int i = 0; i < s.size(); i++ ){
            str += s[i];
            str += '#';
        }
    }

    void findallpallindrome(string str, vector<int> &p){
         int c = 0, r = 0;
         for( int i = 0; i < str.size(); i++ ){
             int mirr = 2*c-i;
             if(i<r){
                p[i] = min(r-i, p[mirr]);
             }
             
             int a = i-(p[i]+1), b = i+(p[i]+1);
             while(a>=0 && b<str.size() && str[a]==str[b]){
                 p[i]++; 
                 a--; b++;
             }

             if(i+p[i]>r){
                 c = i;
                 r = i+p[i];
             }
         }
    }
    string longestPalindrome(string s) {
        string str;
        addhash(s, str);
        
        vector<int> p(str.size());
        findallpallindrome(str, p);
        
        int ind = 0;
        int x = p[0];

        for( int i = 1; i < p.size(); i++ ){
            if(p[i]>x){
                x = p[i];
                ind = i;
            }
        }

        string ans;
        for( int i = ind-x; i<=ind+x; i++ ){
            if(str[i]!='#'){
                ans += str[i];
            }
        }
      return ans;
    }
};