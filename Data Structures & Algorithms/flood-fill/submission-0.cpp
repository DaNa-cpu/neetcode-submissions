class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int reference){
        //Base case
        int rows = image.size();
        int cols = image[0].size();
        if(sr < 0 || sc < 0 || sr == rows || sc == cols || image[sr][sc]!= reference){
            return;
        }

        if(image[sr][sc] == reference){
            image[sr][sc] = color;
        }

        dfs(image, sr + 1, sc, color, reference);
        dfs(image, sr - 1, sc, color, reference);
        dfs(image, sr, sc + 1, color, reference);
        dfs(image, sr, sc - 1, color, reference);

    }

};