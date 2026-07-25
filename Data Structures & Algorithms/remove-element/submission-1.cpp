class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int left = 0; 
        int right = len - 1;

        while( left <= right){
            if(nums[right] == val){
                right--;
            }
            else if(nums[left] == val){
                swap(nums[left], nums[right]);
                right--;
                left++;
            }
            else{
                left++;
            }

        }

        return left;  

    };
};