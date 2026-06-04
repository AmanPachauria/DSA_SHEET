vector<int> allsum(vector<int> &arr, vector<int> &ans, int n, int pos, int sum){
          
          if(pos==n){
              ans.push_back(sum);
              return ans;
          }
          
          allsum(arr,ans,n,pos+1,sum+arr[pos]);
          allsum(arr,ans,n,pos+1,sum);
          
          return ans;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
         
         vector<int> ans;
         allsum(arr, ans, N, 0, 0);
         return ans;
    }