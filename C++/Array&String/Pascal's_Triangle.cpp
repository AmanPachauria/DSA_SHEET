class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> matrix;
        vector<int> pre_vec;
        for(int i = 0; i < numRows; i++ ){
            vector<int> vec;
            for( int j = 0; j <= i; j++ ){
                if(j==0 || j==i){
                    vec.push_back(1);
                }
                else{
                    int a = pre_vec[j]+pre_vec[j-1];
                    vec.push_back(a);
                }
            }

            matrix.push_back(vec);

            pre_vec = vec;
        }

        return matrix;
    }
};