class Solution {
public:
    int findpattern(string a, string b){
        string total = b + "$" + a;
        vector<int> zarr(total.size(),0);
        getzarr(total, zarr);
         for( int i = 0; i < total.size(); i++ ){
             cout<<zarr[i]<<"\n";
            if(b.size()==zarr[i]){
                return i-(b.size()+1);
            }
        }
        return -1;
    }

    void getzarr(string total, vector<int> &zarr){
          int l = 0, r = 0, k;
          for( int i = 1; i < total.size(); i++ ){
              if(i>r){
                  r = i;
                  l = i;
                  while(r<total.size() && total[r-l]==total[r]){
                      r++;
                  }
                  zarr[i] = r-l;
                  r--;
              }
              else{
                  k = i-l;
                  if(zarr[k]<r-i+1){
                      zarr[i] = zarr[k];
                  }
                  else{
                      l = i;
                      while(r<total.size() && total[r-l]==total[r]){
                          r++;
                      }
                      zarr[i] = r-l;
                      r--;
                  }
              }
          }
    }
    int strStr(string haystack, string needle) {
         
         return findpattern(haystack, needle);
    }
};