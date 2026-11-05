class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int size = arr.size();
        int L = 0;
        int target = k*threshold;
        int sum = 0;
        int count = 0;

        for(int R = 0; R < size; R++){
            while(R - L + 1 < k){
                sum += arr[R];
                R++;
            }
            sum += arr[R];
            if(sum >= target) count++;
            sum -= arr[L];
            L++;
        }

        return count;

    }
};