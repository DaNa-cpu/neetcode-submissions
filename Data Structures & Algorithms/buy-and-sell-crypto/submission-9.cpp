class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = 0;
        int size = prices.size();
        int maxProfit = 0;
        
        for(int R = 1; R < size; R++){
            int profit = prices[R] - prices[L];
            if(profit <= 0){
                L = R;
                continue;
            }
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
