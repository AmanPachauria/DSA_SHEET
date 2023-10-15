// Solution 1


int Fun(int day, int last, vector<vector<int>> & points,
 vector<vector<int>> & dp){

    if( dp[day][last] != -1 ) return dp[day][last];
    if(day == 0){

        int maxi = 0;
        for( int i = 0; i < 3; i++ ){
            if( i != last ){
                maxi = max( points[0][i], maxi );
            }
        }

        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for( int task = 0; task < 3; task++ ){
        if( task != last ){
            int point = points[day][task] + Fun( day-1, task, points, dp);
            maxi = max( point, maxi);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n+1, vector<int> (4, -1));

    return Fun(n-1, 3, points, dp);
}


// Solution 2


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(3));

    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    
    for( int i = 1; i < n; i++ ){

        for( int j = 0; j < 3; j++ ){
              
              dp[i][j] = max(dp[i-1][(j+1)%3]+points[i][j], dp[i-1][(j+2)%3]+points[i][j]);
             
              
        }  
    }

    return  max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));

    
}