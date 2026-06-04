class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> s;
        if(nums.size()==0){
            return s;
        }
        vector<int> a, b;
        a.push_back(nums[0]);

        for( int i = 1; i < nums.size(); i++ ){
             if(long(nums[i])-long(nums[i-1])!=1){
                 b.push_back(nums[i-1]);
                 a.push_back(nums[i]);
             }
        }

        if(a.size()>b.size()){
            b.push_back(nums[nums.size()-1]);
        }
        else{
            a.push_back(nums[nums.size()-1]);
            b.push_back(nums[nums.size()-1]);
        }

        
        for( int i = 0; i < a.size(); i++ ){
            string s1;
            if(a[i]==b[i]){
                s1 = to_string(a[i]);
            }
            else{
                string s2 = to_string(a[i]);
                string s3 = to_string(b[i]);

                s1 += s2;
                s1 += "->";
                s1 += s3;
            }
            s.push_back(s1);
        }

        return s;
    }
};