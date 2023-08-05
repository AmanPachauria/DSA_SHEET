// Solutin 1

#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> a, int b) {

     int ans = 0;
     for( int i = 0; i < a.size(); i++ ){
            int allxor = a[i];
            if(allxor==b) ans++;
            for( int j = i+1; j < a.size(); j++ ){
                 allxor = allxor^a[j];
                 if(allxor==b) ans++;
            }
     }

     return ans;
}


// Solution 2

#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> a, int b) {

  unordered_map<int, int> mp;
  int allxor = 0, cnt = 0;
  mp[allxor]++;
  for( int i = 0; i < a.size(); i++ ){
      allxor = allxor^a[i];
      int a1 = allxor^b;
      cnt += mp[a1];
      mp[allxor]++;
      
  }

  return cnt;
}