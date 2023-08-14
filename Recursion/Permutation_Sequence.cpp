class Solution {
public:
    string getPermutation(int n, int ind) {
        int fact = 1;
        vector<int> vec;
        for( int i = 1; i < n; i++ ){
             fact = fact*i;
             vec.push_back(i);
        }
        vec.push_back(n);
        ind = ind-1;
        string ans = "";
        while(true){
          ans += to_string(vec[ind/fact]);
          vec.erase(vec.begin()+ind/fact);
          if(vec.size()==0){
               break;
          }

          ind = ind%fact;
          fact = fact/vec.size();

        }

        return ans;
    }
};