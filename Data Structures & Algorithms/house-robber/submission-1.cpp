class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memoization(nums.size(), -1);
        return max(recursive(nums, 0, memoization), recursive(nums, 1, memoization));
    }

    int recursive(vector<int>& nums, int pozition, vector<int>& memoization){
        if(pozition >= nums.size()) return 0;
        if(memoization[pozition] == -1){
            memoization[pozition] = nums[pozition] + 
                max(recursive(nums, pozition + 2, memoization), recursive(nums, pozition + 3, memoization));
        }
        return memoization[pozition];
    }
};