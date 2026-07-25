class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int left = 0; 
        int right = 0;

        while( right< len ){
            if(nums[right]!=val){
                nums[left] = nums[right];
                left++;
            }
            right++;
        }

        return left;  

    };
};