class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();

        for(int L = 0; L < size - 1; L++){
            int R = L + 1;
            while(R < size && R - L <= k){
                if(nums[L] == nums[R]) return true;
                else R++;
            }
        }
        return false;
    }
};