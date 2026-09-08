class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for(int& color : nums){
            count[color]++;
        }

        int i = 0;
        for(int color = 0; color < count.size(); color++){
            while(count[color]-- > 0){
                nums[i++] = color;
            }
        }
    }
};