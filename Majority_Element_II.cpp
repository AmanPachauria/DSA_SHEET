// Solution 1

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> mp;
        for( int i = 0; i < n; i++ ){
            mp[nums[i]]++;
        }

        vector<int> vec;
        for(auto it : mp){
            if(it.second>n/3) vec.push_back(it.first);
        }

        return vec;
    }
};


// Solution 2

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int cnt1 =0, cnt2 = 0;
        int el1 = INT_MIN,el2 = INT_MIN;
        for( int i = 0; i < n; i++ ){
            if(cnt1==0 && el2!=nums[i]){
                cnt1 = 1; el1 = nums[i];
            }
            else if(cnt2 == 0 && el1!=nums[i]){
                cnt2 = 1; el2=nums[i];
            }
            else if(el1==nums[i]) cnt1++;
            else if(el2==nums[i]) cnt2++;
            else{
                cnt1--; cnt2--;
            }
        }

        vector<int> vec;
        cnt1=0; cnt2=0;
        for(int i = 0; i < n; i++ ){
             if(nums[i]==el1) cnt1++;
             else if(nums[i]==el2) cnt2++;
        }

        if(cnt1>n/3) vec.push_back(el1);
        if(cnt2>n/3) vec.push_back(el2);

        return vec;
    }
};