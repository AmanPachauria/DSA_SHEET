class Solution {
public:
    
    int climbStairs(int n) {
       
       if(n==1) return 1;
       int pre = 1;
       int ans = 2;
       for( int i = 3; i <= n; i++ ){
           int cnt = ans + pre;
           pre = ans;
           ans = cnt;

       }

       return ans;
    }
};