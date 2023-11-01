// Solution 1

#include <bits/stdc++.h>

string findLCS(int n, int m,string &s1, string &s2){
    
	vector<vector<string>> dp(n+1, vector<string> (m+1));

	for( int i = 0; i <= m; i++ ){
		dp[0][i] = "";
	}	
	for( int i = 0; i <= n; i++ ){
        dp[i][0] = "";
	}

	for( int i = 1; i <= n; i++ ){
		for( int j = 1; j <= m; j++ ){

			if( s1[i-1] == s2[j-1] ){
				dp[i][j] = dp[i-1][j-1] + s1[i-1];
			}
			else{
				string a = dp[i-1][j];
				string b = dp[i][j-1];
				
				dp[i][j] = ( a.size()>= b.size() ) ? a : b;
			}
		}
	}

	return dp[n][m];
}



// Solution 2

#include <bits/stdc++.h>

string findLCS(int n, int m,string &s1, string &s2){
    
	vector<vector<int>> dp(n+1, vector<int> (m+1));

	for( int i = 0; i <= m; i++ ){
		dp[0][i] = 0;
	}	
	for( int i = 0; i <= n; i++ ){
        dp[i][0] = 0;
	}

	for( int i = 1; i <= n; i++ ){
		for( int j = 1; j <= m; j++ ){

			if( s1[i-1] == s2[j-1] ){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				
				dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
			}
		}
	}
    
	string str = "";

    int i = n, j = m;

	while( i > 0 && j > 0 ){

		if( s1[i-1] == s2[j-1] ){
			str += s1[i-1];
			i--;
			j--;
		}
		else if( dp[i][j-1] >= dp[i-1][j] ){
			j--;
		}
		else{
			i--;
		}
	}
	
	reverse( str.begin(), str.end() );
	
	return str;

}