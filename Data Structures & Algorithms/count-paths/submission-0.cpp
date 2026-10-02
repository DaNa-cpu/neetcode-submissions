class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, memo);
    }

    int dfs(int r, int c, int m, int n, vector<vector<int>>& memo){
        if( r == m || c == n ) return 0;
        if( r == m - 1 && c == n - 1) return 1;
        if( memo[r][c] != -1 ) return memo[r][c];

        int count = 0;

        count += dfs(r + 1, c, m, n, memo);
        count += dfs(r, c + 1, m, n, memo);

        return memo[r][c] = count;
    }
};

