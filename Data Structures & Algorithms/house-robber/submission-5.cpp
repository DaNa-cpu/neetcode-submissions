class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memoization(nums.size(), -1);
        return recursive(nums, 0, memoization);
    }

    int recursive(vector<int>& nums, int pozition, vector<int>& memoization){
        if(pozition >= nums.size()) return 0;
        if(memoization[pozition] == -1){
            memoization[pozition] =  max(
                recursive(nums, pozition + 1, memoization), 
                nums[pozition] + recursive(nums, pozition + 2, memoization)
                );
        }
        return memoization[pozition];
    }
};