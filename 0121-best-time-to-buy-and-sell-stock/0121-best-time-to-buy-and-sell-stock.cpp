class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = l + 1;

        int max_profit = 0;
        int profit = 0;

        while(r < prices.size())
        {
            profit = prices[r] - prices[l];

            if(profit < 0)
            {
                l = r;
            }
            else
            {
                max_profit = max(max_profit,profit);
            }
            r++;
            
        }
        return max_profit;
        
    }
};
