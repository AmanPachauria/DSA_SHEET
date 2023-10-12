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