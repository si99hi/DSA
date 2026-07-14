class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int maxEl= nums[0];
        int minEl= nums[0];
        for(int num: nums){
            maxEl= max(maxEl, num);
            minEl= min(minEl, num);
        }

        long long  bestVal= (long long)maxEl- minEl;
        return bestVal*k;
        
    }
};