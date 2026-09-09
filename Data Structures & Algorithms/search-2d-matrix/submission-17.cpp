class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;

        int top = 0;
        int bottom = rows;
        int row;

        while(top <= bottom){
            int midRow = (top + bottom) / 2;
            if(target > matrix[midRow][cols]){
                top = midRow + 1;
            }else if(target < matrix[midRow][0]){
                bottom = midRow - 1;
            }else{
                row = midRow;
                break;
            }
        }
        if(top > bottom) {
            return false;
        }

        int left = 0;
        int right = cols;

        while(left <= right){
            int midCol = (left + right) / 2;
            if(target > matrix[row][midCol]){
                left = midCol + 1;
            }else if(target < matrix[row][midCol]){
                right = midCol - 1;
            }else{
                return true;
            }
        }
        return false;
    }

};
