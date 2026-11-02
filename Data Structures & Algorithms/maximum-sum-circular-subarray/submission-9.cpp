class Solution {
public: 
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = nums[0];
        int curMin = 0;

        int maxSum = nums[0];
        int curMax = 0;

        int total = 0;

        for(auto n: nums){
            if(curMax < 0) curMax = 0;
            curMax +=n;
            maxSum = max(maxSum, curMax);

            if(curMin > 0) curMin = 0;
            curMin +=n;
            minSum = min(minSum, curMin);

            total += n;
        }
        return maxSum < 0 ? maxSum : max(maxSum, total-minSum);

    }
};