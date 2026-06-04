// Solution 1

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        map<int,int> mp;
        for( int i = 0; i < nums.size(); i++ ){
              mp[nums[i]]++;
        }

        for(auto it : mp){
            if(it.second>(nums.size()/2)) return it.first;
        }

        return 0;
    }
};


//  Solution 2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 1, element = nums[0];
        
        for( int i = 1; i < nums.size(); i++ ){
            if(element == nums[i]){
                count++;
            }
            else count--;
            if(count==0){
                count = 1;
                element = nums[i];
            }
        }

        return element;
    }
};