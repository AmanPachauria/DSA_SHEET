// Solution 1 


#include <bits/stdc++.h> 

int Fun( int ind, int maxWeight, vector<int> &wt, vector<int> &value, vector<vector<int>> &dp ){

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