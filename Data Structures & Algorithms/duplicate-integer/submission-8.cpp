class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> sets;
        for(auto& num : nums){
            sets.insert(num);
        }
        if(sets.size()==nums.size()){
            return false;
        }
        return true;
    }
};