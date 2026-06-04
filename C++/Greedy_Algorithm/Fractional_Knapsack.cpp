#include <bits/stdc++.h> 

bool compare(vector<double> v1, vector<double> v2){
     return v1[0]<v2[0];
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
     vector<vector<double>> mat;

     vector<double> v;
     for( int i = 0; i < n; i++ ){
         double a = items[i].first*1.00, b = items[i].second*1.00;
         double c = a/b;
         v.push_back(c);
         v.push_back(a);
         v.push_back(b);

         mat.push_back(v);
         v.clear();
     }

     sort(mat.begin(), mat.end(), compare);
     double ans = 0;
     for( int i = 0; i < n; i++ ){
          if(w>=mat[i][1]){
              ans += mat[i][2];
              w -= mat[i][1];
          }
          else{
              ans += (w/(mat[i][1]))*mat[i][2];
              break;
          }
     }

     return ans;


}