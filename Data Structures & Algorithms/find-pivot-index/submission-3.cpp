class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefixL = 0;
        int total = 0;

        for(int n: nums){
            total += n;
        }

        for(int i = 0; i < nums.size(); i++){
            int prefixR = total - prefixL - nums[i];

            if(prefixL == prefixR) return i;
            prefixL += nums[i];
        }

        return -1;
        // Only for positive
        // int L = 0;
        // int R = nums.size() - 1;

        // int prefLeft = nums[L];
        // int prefRight = nums[R];

        // while(L < R){
        //     if(prefLeft <= prefRight){
        //         L++;
        //         prefLeft += nums[L];
        //     }else{
        //         R--;
        //         prefRight += nums[R];
        //     }
        // }
        // return prefLeft != prefRight && L == R? -1 : L;

    }
};