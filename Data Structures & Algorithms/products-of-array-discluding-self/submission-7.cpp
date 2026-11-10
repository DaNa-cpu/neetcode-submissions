class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product(nums.size());

        int prodL = 1, prodR = 1;

        for(int i = nums.size() - 1; i >= 0; i--){
            product[i] = prodR;
            prodR *= nums[i];
        }

        for(int j = 0; j < nums.size(); j++){
            product[j] *= prodL;
            prodL *= nums[j];
        }

        return product;
    }
};
