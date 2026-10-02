class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for( int i = 0; i <= n; i++){
            int binary = i;
            while( binary > 0){
                if( binary & 1 == 1) result[i]++;
                binary = binary >> 1;
            }
        }
        return result;
    }
};
