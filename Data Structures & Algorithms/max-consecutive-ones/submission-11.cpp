class Solution{

public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int length = nums.size();
        int maxNum = 0;
        int sum = 0;

        for(int i=0; i<length; i++){
            if(sum < sum + nums[i]){
                sum += nums[i];
                maxNum = max(sum, maxNum);
                }
            else {
                sum = 0;
                }
        }
        
        return maxNum;
    
    };
};