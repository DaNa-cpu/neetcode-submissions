class Solution {
private:
    int getMax(vector<int>& arr, int poz){
        int len = arr.size();
        int max = -1;
        for( int i= poz + 1 ; i<len; i++){
            if(max <= arr[i]){
                max = arr[i];
            }
        }
        return max;
    }

public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();

        for( int i = 0; i < len; i++ ){
            arr[i] = getMax(arr, i);
        }
        return arr;
    }
};