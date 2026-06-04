// Solution 1

#include <bits/stdc++.h> 

bool Fun(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){

	if(target==0) 
	   return dp[ind][target] = true;
	
	if(ind == 0 ){
		return dp[ind][target] = (arr[ind]==target);
	}

	if(dp[ind][target] != -1) return dp[ind][target];

	bool nottake = Fun( ind-1, target, arr, dp );
    
	bool take = false;
	if( arr[ind] <= target ){
		take = Fun( ind-1, target - arr[ind], arr, dp );
	}

	return dp[ind][target] = (nottake | take);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int tosum = 0;
	for( int i = 0; i < n; i++ ){
		tosum += arr[i];
	}

	int sum = tosum;

	tosum = tosum/2;

	vector<vector<int>> dp(n, vector<int> (tosum+1, -1));

	for( int i = 0; i <= tosum; i++ ){
		Fun(n-1, i, arr, dp);
	}

	int ans = 1e9;
	for( int i = 0; i <= tosum; i++ ){
		
		if(dp[n-1][i]==true){
           int value = abs(i - sum);
		   value = abs( i - value );
		    ans = min(ans, value);
		}
        
	}

	return ans;
}



// Solution 2

#include <bits/stdc++.h> 

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int tosum = 0;
	for( int i = 0; i < n; i++ ){
		tosum += arr[i];
	}

	int sum = tosum;

	tosum = tosum/2;

	vector<vector<bool>> dp(n, vector<bool> (tosum+1, false));

	for( int i = 0; i < n; i++ ){
		dp[i][0] = true;
	}

	if( arr[0] <= tosum ){
		dp[0][arr[0]] = true;
	}

	for( int ind = 1; ind < n; ind++ ){
		for( int target = 1; target <= tosum; target++ ){

			bool nottake = dp[ind-1][target];
    
            bool take = false;
			if( arr[ind] <= target ){
				take = dp[ind-1][target-arr[ind]];
			}

			dp[ind][target] = (nottake | take );
		}
	}

	int ans = 1e9;
	for( int i = 0; i <= tosum; i++ ){

		if(dp[n-1][i]==true){
           int value = abs(i - sum);
		   value = abs( i - value );
		    ans = min(ans, value);
		}
        
	}

	return ans;
}
