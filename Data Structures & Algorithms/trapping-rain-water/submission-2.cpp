class Solution {
public:
    int trap(vector<int>& height) {
        // Two pointers: T: O(n), S: O(1)
        if(height.empty()) return 0;

        int L = 0, R =  height.size() - 1;
        int maxL = height[L], maxR = height[R];

        int totalWater = 0; 
        while(L < R){
            if(height[L] <= height[R]){
                L++;
                totalWater += max(0, maxL - height[L]); // 0 instead of negative water
                maxL = max(maxL, height[L]);
            }else{
                R--;
                totalWater += max(0, maxR - height[R]); // 0 instead of negative water
                maxR = max(maxR, height[R]);
            }
        }
        return totalWater;
        // Brute force T: O(n), S: O(n);
        // int maxLeft = 0;
        // int maxRight = 0;

        // vector<int> maxLefts(height.size());
        // vector<int> maxRights(height.size());
        // int water = 0;

        // for(int i = 0; i < height.size(); i++){
        //     maxLefts[i] = maxLeft;
        //     maxLeft = max(maxLeft, height[i]);
        // }
        // for(int i = height.size() - 1; i >= 0 ; i--){
        //     maxRights[i] = maxRight;
        //     maxRight = max(maxRight, height[i]);
        // }

        // for(int j = 0; j < height.size(); j++){
        //     int retaind = min(maxRights[j], maxLefts[j]) - height[j];
        //     water += max(0, retaind);
        // }
        // return water;
    }
};
