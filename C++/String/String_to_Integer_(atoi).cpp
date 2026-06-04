class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(s[i]==' '){
            i++;
        }
        int positive = 0, negative = 0;
        if(s[i]=='+'){
            positive++;
            i++;
        }
        if(s[i]=='-'){
            negative++;
            i++;
        }
        
        double ans = 0;
        while(i<n and s[i]>='0' and s[i]<='9'){
              ans = (ans * 10) + (s[i]-'0');
              i++;
        }

        if(negative>0){
            ans = -ans;
        }
        cout<<positive<<" "<<negative<<"\n";
        if(positive>0 && negative>0){
            return 0;
        }

        if(ans>INT_MAX){
            ans = INT_MAX;
        }
        if( ans<INT_MIN){
            ans = INT_MIN;
        }

        return (int)ans;
    }
};