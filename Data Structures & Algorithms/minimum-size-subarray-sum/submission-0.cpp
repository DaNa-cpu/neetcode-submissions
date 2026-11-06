class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0;
        int size = nums.size();
        int minLength = size + 1;
        int sum = 0;

        for(int R = 0; R < size; R++){
            sum += nums[R];
            while(sum >= target){
                minLength = min(minLength, R - L + 1);
                sum -= nums[L];
                L++;
            }
            
        }
        return minLength <= size ? minLength : 0;

    }
};