class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        int size = nums.size();
        int L = 0;
        seen.insert(nums[L]);

        for(int R = 1; R < size; R++){
            if(seen.count(nums[R])) return true;
            seen.insert(nums[R]);
            if(R - L >= k){
                seen.erase(nums[L]);
                L++;
            }
        }
        return false;

        // T: O(n*k)
        // S: O(1)
        // for(int L = 0; L < size - 1; L++){
        //     int R = L + 1;
        //     while(R < size && R - L <= k){
        //         if(nums[L] == nums[R]) return true;
        //         else R++;
        //     }
        // }
        // return false;
    }
};