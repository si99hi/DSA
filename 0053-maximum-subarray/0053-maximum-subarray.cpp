class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=nums[0];
        int maxSum= nums[0];
        for(int i=1; i<=nums.size()-1; i++){
            currsum= max(nums[i], currsum+ nums[i]);
            maxSum= max(maxSum, currsum);
        }
        return maxSum;

        
    }
};