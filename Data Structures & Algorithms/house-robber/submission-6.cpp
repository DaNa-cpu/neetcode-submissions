class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(2);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for( int i = 2; i < nums.size(); i++){
            int tmp = max(dp[1], dp[0] + nums[i]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    //     vector<int> memoization(nums.size(), -1);
    //     return recursive(nums, 0, memoization);
    // }
    // int recursive(vector<int>& nums, int pozition, vector<int>& memoization){
    //     if(pozition >= nums.size()) return 0;
    //     if(memoization[pozition] == -1){
    //         memoization[pozition] =  max(
    //             recursive(nums, pozition + 1, memoization), 
    //             nums[pozition] + recursive(nums, pozition + 2, memoization)
    //             );
    //     }
    //     return memoization[pozition];
    }
};