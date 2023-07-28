class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit=0;
        int a=prices[0];
        for(int i=1; i<prices.size(); i++){
            if(a>prices[i]){
                a=prices[i];
            }
            else if(a<prices[i] && profit<prices[i]-a){
                profit=prices[i]-a;
                
            }
        }
        
        return profit;
        
    }
};