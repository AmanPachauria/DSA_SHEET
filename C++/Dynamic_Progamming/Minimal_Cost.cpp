// Solution 1


int Jump(int ind, int k, vector<int> &height, vector<int> &dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int mnvalue = INT_MAX;
    for( int i = 1; i <= k; i++ ){
        if(ind-i>=0){
            int value = Jump(ind-i, k, height, dp) + abs(height[ind] - height[ind-i]);
            mnvalue = min(mnvalue, value);
        }
    }

    return dp[ind] = mnvalue;
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n+1, -1);
    return Jump(n-1, k, height, dp);
}

// Solution 2



int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n+1, -1);
    dp[0] = 0;

    for(int i = 1; i < n; i++ ){
        int mnstep = INT_MAX;
        for( int j = 1; j <= k; j++ ){
            if(i-j>=0){
                int Jumpans = dp[i-j] + abs(height[i]-height[i-j]);
                mnstep = min(Jumpans, mnstep);
            }
        }

        dp[i] = mnstep;
    }

    return dp[n-1];
}