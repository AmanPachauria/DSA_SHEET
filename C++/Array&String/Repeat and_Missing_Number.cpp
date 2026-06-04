#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	 sort(arr.begin(), arr.end());
	 pair<int,int> p;
	 int cnt = 0;
	 for( int i = 1; i < n; i++ ){
		 if(arr[i]-arr[i-1]>1){
			 cnt = 1;
			 p.first = arr[i-1]+1;
		 }
		 if(arr[i]==arr[i-1]){
			 p.second = arr[i];
		 }
	 }
	 if(cnt == 0 && arr[n-1]!=n) p.first = n;
	 else if(cnt == 0 && arr[n-1]==n) p.first = 1;
	
	return p;
}
