vector<int> MinimumCoins(int n)
{
    vector<int> v = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    
    vector<int> ans;
    for( int i = 0; i < v.size(); i++ ){

         while(n>=v[i]){
            ans.push_back(v[i]);
            n -= v[i];
         }
    }

    return ans;

}