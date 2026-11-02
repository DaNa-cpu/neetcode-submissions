class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;

        for(auto n: nums){
            if(sum < 0){
                sum = 0;
            }
            sum += n;
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
