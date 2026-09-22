class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if( freq.contains(diff)){
                return {freq[diff], i};
            }else{
                freq[nums[i]] = i;
            }
        }
        return {};
    }
};
