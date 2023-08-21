#include <bits/stdc++.h> 
// #define int long long
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	 
	if(n>m) return -1;
	 long long low = 1, high = 0;
	 for( int i = 0; i < m; i++ ){
		 high += time[i];
         low = max(low, time[i]*1LL);
	 }

	 while(low<=high){
		 long long mid = low + (high-low)/2;

		 long long cnt = 1;
		 long long sum = 0;
		 for( int i = 0; i < m; i++ ){
			  if(sum+time[i] <= mid){
				  sum += time[i];
			  }
			  else{
				  cnt++;
				  sum = time[i];
			  }
		 }

		 if(cnt>n) low = mid+1;
		 else high = mid-1;
	 }

	 return low;
}