class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int L1 = 0;
        int L2 = 0;
        int maxLen = 1;

        for(int R = 1; R < arr.size(); R++){
            if( ((R - 1) % 2 == 1 && arr[R - 1] <= arr[R]) ||
             ((R - 1) % 2 == 0 && arr[R - 1] >= arr[R]) ){
                L1 = R;
            }
            if( ((R - 1) % 2 == 1 && arr[R - 1] >= arr[R]) ||
             ((R - 1) % 2 == 0 && arr[R - 1] <= arr[R]) ){
                L2 = R;
            }
            maxLen = max({maxLen, R - L1 + 1, R - L2 + 1});
        }
        return maxLen;
    }
};