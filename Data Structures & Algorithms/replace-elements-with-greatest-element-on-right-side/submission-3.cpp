class Solution {

public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        int rightMax = -1;
        for( int i = len - 1 ; i >= 0; i-- ){
            int temp = arr[i];
            arr[i] = rightMax;
            rightMax = max(rightMax, temp);
        }
        return arr;
    }
};