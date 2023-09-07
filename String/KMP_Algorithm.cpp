class Solution {
public:
   
    void findlps(string str, vector<int> &lps){
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while(i<str.size()){
            if(str[len]==str[i]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len==0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
    }

    int findind(string str, string pat, vector<int> lps){
        int i = 0, j = 0;
        while(i<str.size()){
            if(str[i]==pat[j]){
                i++;
                j++;
                if(j==pat.size()){
                    return i-j;
                }
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
         
         vector<int> lps(needle.size(), -1);
         findlps(needle, lps);

         return findind(haystack, needle, lps);
    }
};