
// Solution 1 

int Findmax( int ind, int wt, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp ){

    if( ind == 0 ){
       if( weight[0] <= wt ) return profit[0] * (wt/weight[0]);
       else return 0;
    }

    if( dp[ind][wt] != -1 ) return dp[ind][wt];

    int nottake = Findmax( ind-1, wt, profit, weight, dp );
    int take = 0;
    if( weight[ind] <= wt ){
        take = profit[ind] + Findmax( ind, wt - weight[ind], profit, weight, dp );
    }

    return dp[ind][wt] = max( nottake, take );
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    
    vector<vector<int>> dp( n, vector<int> (w+1, -1 ));

    return Findmax( n-1, w, profit, weight, dp );
}


// Solution 2



int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    
    vector<vector<int>> dp( n, vector<int> (w+1, 0 ));

    for( int i = 0; i <= w; i++ ){
        if( weight[0] <= i ){
            dp[0][i] = profit[0] * (i / weight[0]);
        }
    }

    for( int ind = 1; ind < n; ind++ ){
        for( int target = 0; target <= w; target++ ){

            int nottake = dp[ind-1][target];
            int take = 0;
            if( weight[ind] <= target ){
                take = profit[ind] + dp[ind][target-weight[ind]];
            }

            dp[ind][target] = max(nottake, take );
        }
    }

    return dp[n-1][w];
}


// Solutin 2

