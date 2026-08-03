class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice= prices[0];
        int maxProfit=0;
        for(int i=0; i<=prices.size()-1; i++){
            minPrice= min(minPrice, prices[i]);
            maxProfit= max(maxProfit, prices[i]-minPrice);
        }
        return maxProfit;

        
    }
};