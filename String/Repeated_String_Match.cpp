class Solution {
public:
    int repeatedStringMatch(string a, string b) {
         if(a==b) return 1;
         int ans = 1;
         string s1 = a;
         while(s1.size()<b.size()){
             ans++;
             s1 += a;
         }
         
         int found = s1.find(b);
         
         if(found != string::npos){
             return ans;
         }
         s1 += a;
         found = s1.find(b);
         if(found != string::npos){
             return ans+1;
         }

         return -1;
    }
};

// abcd =>  cd