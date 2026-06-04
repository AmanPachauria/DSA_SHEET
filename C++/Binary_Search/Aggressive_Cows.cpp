#include <bits/stdc++.h>

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n-1]-stalls[0];

    while(low<=high){
        int mid = low + (high - low)/2;

        int cows = 1;
        int start = stalls[0];
        for(int i = 0; i < n; i++ ){
             if(stalls[i]-start>=mid){
               
                  cows++;
                  start = stalls[i];
             }
        }
        
        if(cows>=k) low = mid+1;
        else  high = mid-1;

    }

    return high;
}