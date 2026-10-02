class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        return dfs(0,0,rows, cols, obstacleGrid, memo);
    }

    int dfs(int r, int c, int rows, int cols, vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo){
        if( r == rows || c == cols || obstacleGrid[r][c] == 1) return 0;
        if( memo[r][c] > -1) return memo[r][c];
        if (r == rows - 1 && c == cols - 1) return 1;

        memo[r][c] = dfs(r, c + 1, rows, cols, obstacleGrid, memo) + 
                    dfs(r + 1, c, rows, cols, obstacleGrid, memo);

        return memo[r][c];
    }
};