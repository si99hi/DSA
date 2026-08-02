class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=prices[0];
        int maxProf= 0;
        for(int i=1;i<n; i++){
            minPrice= min(prices[i], minPrice);
            maxProf= max(maxProf, prices[i]-minPrice);
        }
        return maxProf;
        
    }
};