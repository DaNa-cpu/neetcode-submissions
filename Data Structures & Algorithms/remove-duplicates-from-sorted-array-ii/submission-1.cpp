class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> freq;
        int L = 0;
        int R = 1;
        freq[nums[L]]++;

        while(R < nums.size()){
            freq[nums[R]]++;
            if(nums[L] == nums[R] && freq[nums[R]] == 2 || nums[L] != nums[R]){
                L++;
                nums[L] = nums[R];
            }
            R++;
        }
        return L + 1;
    }
};