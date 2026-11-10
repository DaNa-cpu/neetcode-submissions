class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = 0;
        int maxRight = 0;

        vector<int> maxLefts(height.size());
        vector<int> maxRights(height.size());
        int water = 0;

        for(int i = 0; i < height.size(); i++){
            maxLefts[i] = maxLeft;
            maxLeft = max(maxLeft, height[i]);
        }
        for(int i = height.size() - 1; i >= 0 ; i--){
            maxRights[i] = maxRight;
            maxRight = max(maxRight, height[i]);
        }


        for(int j = 0; j < height.size(); j++){
            int retaind = min(maxRights[j], maxLefts[j]) - height[j];
            water += max(0, retaind);
        }
        return water;
    }
};
