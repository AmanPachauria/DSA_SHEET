//  Solution 1

#include <bits/stdc++.h>

int Frog(int ind, vector<int> &heights, vector<int> &dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int right = INT_MAX;
    int left = Frog(ind-1, heights, dp) + abs(heights[ind]-heights[ind-1]);
    if(ind>1){
       right = Frog(ind-2, heights, dp) + abs(heights[ind]-heights[ind-2]);
    }

    return dp[ind] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{   
    vector<int> dp(n, -1);
    return Frog(n-1, heights, dp);
}



// Solution 2 

#include <bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{   
    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(heights[1]-heights[0]);
    
    for( int i = 2; i < n; i++ ){
        int one = abs(heights[i]-heights[i-1]);
        int two = abs(heights[i]- heights[i-2]);
        dp[i] = min(dp[i-1] + one, dp[i-2] + two);
    }

    return dp[n-1];

}