class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int L = 0; L < nums.size(); L++) {
            for (int R = L + 1; R < min((int)nums.size(), L + k + 1); R++) {
                if (nums[L] == nums[R]) {
                    return true;
                }
            }
        }
        return false;
    }
};