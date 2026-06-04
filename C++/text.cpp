#include <bits/stdc++.h> 

int Fun(ind, maxWeight, wt, value, dp ){

	if(ind == 0 ){
		if( wt[ind] <= maxWeight ) return value[0];
		else return 0;
	}

	if( dp[ind][maxWeight] != -1 ) return dp[ind][maxWeight];

	int nottake = Fun( ind-1, maxWeight, wt, value, dp );
	int take = 0;
	if( wt[ind] <= maxWeight ){
		take = value[ind] + Fun(ind-1, maxWeight - wt[ind] , wt, value, dp );
	}

	return dp[ind][maxWeight] = max( nottake, take );
}

int knapsack(vector<int> wt, vector<int> value, int n, int maxWeight) 
{   
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));

	return Fun( n-1, maxWeight, wt, value, dp );
	
}


// Solution 2 


#include <bits/stdc++.h> 

int knapsack(vector<int> wt, vector<int> value, int n, int maxWeight) 
{   
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));

	for( int i = wt[0]; i <= maxWeight; i++ ){
		dp[0][i] = value[0];
	}
	

	for( int ind = 1; ind < n; ind++ ){
       for( int target = 1; target <= maxWeight; target++ ){
		    
			int nottake = dp[ind-1][target];
			int take = 0;
			if( wt[ind] <= target ){
				take = value[ind] + dp[ind-1][target-wt[ind]];
			}

			dp[ind][target] = max( nottake, take );
	   }
	}

	return dp[n-1][maxWeight];
}