class NumMatrix {
private:
    vector<vector<int>> rowPrefix;
public:
    NumMatrix(vector<vector<int>>& matrix){
        for(int i = 0; i < matrix.size(); i++){
            int prefix = 0;
            vector<int> currRowPref;
            for(int j = 0; j < matrix[0].size(); j++){
                prefix += matrix[i][j];
                currRowPref.push_back(prefix);
            }
            rowPrefix.push_back(currRowPref);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2){
        int sumReg = 0;
        for(int i = row1; i <= row2; i++){
            if(col1 == 0) sumReg += rowPrefix[i][col2];
            else sumReg += rowPrefix[i][col2] - rowPrefix[i][col1 - 1];
        }
        return sumReg;
    }    
    
    // Prefix Sum: T: O(n), S: O(1)
    // Brute force: T: O(n^2), S: O(1)
// private:
//     vector<vector<int>> matrix;
// public:
//     NumMatrix(vector<vector<int>>& matrix) {
//         this->matrix = matrix;
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         int sum = 0;
//         for( int i = row1; i <= row2; i++)
//             for(int j = col1; j <= col2; j++){
//                 sum += matrix[i][j];
//             }
//         return sum;
//     }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */