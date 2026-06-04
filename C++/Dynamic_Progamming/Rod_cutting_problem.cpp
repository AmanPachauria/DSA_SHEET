// Solution 1


int Findmax( int ind, int target, vector<int> &price, vector<vector<int>> &dp ){

	if( ind == 0 ){
		return price[0] * target;
	}

	if( dp[ind][target] != -1 ) return dp[ind][target];

	int nottake = Findmax( ind-1, target, price, dp );
	int take = -1e9;
	if( ind+1 <= target ){
	    take = price[ind] + Findmax( ind, target - (ind+1), price, dp );
	}

	return dp[ind][target] = max( nottake, take );
}

int cutRod(vector<int> &price, int n)
{   
	
	vector<vector<int>> dp(n, vector<int> (n+1, -1));
    
	return Findmax( n-1, n, price, dp );
}













// Solution 2




int cutRod(vector<int> &price, int n)
{   
	
	vector<vector<int>> dp(n, vector<int> (n+1, 0));

	for( int i = 0; i <= n; i++ ){
		dp[0][i] = price[0] * i;
	}
    
	for( int ind = 1; ind < n; ind++ ){
		for( int target = 0; target <= n; target++ ){
			   
			   int nottake = dp[ind-1][target];
			   int take = 0;
			   if( ind + 1 <= target ){
				   take = price[ind] + dp[ind][target-(ind+1)];
			   }

			   dp[ind][target] = max( nottake, take );
		}
	}

	return dp[n-1][n];
}
