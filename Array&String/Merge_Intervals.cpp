class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> vp;
        int n = intervals.size();

        for( int i = 0; i < n; i++ ){
            pair<int,int> vp1;
            for(int j = 0; j < 2; j++ ){
                if(j==0) vp1.first = intervals[i][j];
                else vp1.second = intervals[i][j];
            }
            vp.push_back(vp1);
        }
         
         sort(vp.begin(),vp.end());
        for( int i = 1; i < vp.size(); i++ ){
            if(vp[i].first<=vp[i-1].second){
                vp[i-1].second = max(vp[i-1].second, vp[i].second);
                vp[i].first = vp[i-1].first;
                vp[i].second = vp[i-1].second;
            }
        }
        vector<vector<int>> mat;
        vector<int> vec(2);
        vec[0] = vp[0].first;
        vec[1] = vp[0].second;
        for( int i = 1; i < vp.size(); i++ ){
            if(vec[0] == vp[i].first){
                vec[1] = vp[i].second;
            }
            else{
                mat.push_back(vec);
                vec[0] = vp[i].first;
                vec[1] = vp[i].second;
            }
        }

        mat.push_back(vec);
         
        return mat;
    }
};