class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice= prices[0];
        int maxProf= 0;
        for(int i=0; i<prices.size(); i++){
            minPrice= min(prices[i], minPrice);
            maxProf= max(maxProf, prices[i]-minPrice);
        }
        return maxProf;
        
    }
};