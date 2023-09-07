class Solution {
public:
    int compareVersion(string version1, string version2) {
           
           int i = 0, j = 0;
           while(i<version1.size() && j < version2.size()){
                 string s1, s2;
                 while(version1[i]!='.' && i<version1.size()){
                     s1 += version1[i];
                     i++;
                 }

                 while(version2[j]!='.' && j<version2.size()){
                     s2 += version2[j];
                     j++;
                 }
                 int a = stoi(s1);
                 int b = stoi(s2);
                 if(a>b) return 1;
                 else if(b>a) return -1;
                 i++; j++;
           }

           while(i<version1.size()){
               string s1;
               while(i<version1.size() && version1[i]!='.'){
                    s1 += version1[i];
                    i++;
               }
               int a = stoi(s1);
               if(a>0) return 1;
               i++;
           }

           while(j<version2.size()){
               string s1;
               while(j<version2.size() && version2[j]!='.'){
                   s1 += version2[j];
                   j++;
               }
               int a = stoi(s1);
               if(a>0) return -1;
               j++;
           }
           

           return 0;
    }
};