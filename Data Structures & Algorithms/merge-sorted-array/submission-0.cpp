class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums = { nums1.begin(), nums1.begin() + m };

        int i = 0;
        int j = 0;
        int k = 0;

        while( i < nums.size() && j < nums2.size()){
            if(nums[i] <= nums2[j]){
                nums1[k] = nums[i++];
            } else {
                nums1[k] = nums2[j++];
            }
            k++;
        }
        while( i < nums.size()){
            nums1[k++] = nums[i++];
        }
        while (j < nums2.size()){
            nums1[k++] = nums2[j++];
        }
    }
};