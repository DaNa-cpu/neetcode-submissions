class NumArray {
private:
    vector<int> prefixes;

public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int n: nums){
            sum +=n;
            prefixes.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int sum;
        if(left == 0) return prefixes[right];
        else if(left <= right){
            sum = prefixes[right] - prefixes[left - 1];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */