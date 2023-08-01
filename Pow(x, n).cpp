// Solution 1 

class Solution {
public:
    double myPow(double x, int n) {
        double db = pow(x,n);
        return db;
    }
};

// Solution 2

class Solution {
public:
    double mypow(double x, int n){
        double ans = 1;
        int nn = n;
        while(nn){
            if(nn%2){
                ans = ans * x;
            }
                nn = nn/2;
                x = x*x;
        }
       if(n<0) ans = double(1)/ans;
       return ans;
    }
    double myPow(double x, int n) {
        double db = mypow(x,n);
        return db;
    }
};