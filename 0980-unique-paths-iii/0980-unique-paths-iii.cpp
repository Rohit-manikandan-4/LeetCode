class Solution {
public:
    int rows, cols;

    int dfs(vector<vector<int>>& grid, int r, int c, int remaining) {
        // Out of bounds or obstacle
        if (r < 0 || r >= rows || c < 0 || c >= cols ||
            grid[r][c] == -1)
            return 0;

        // Reached the ending cell
        if (grid[r][c] == 2) {
            if (remaining == 1)
                return 1;
            return 0;
        }

        // Mark current cell as visited
        grid[r][c] = -1;

        int paths = 0;

        paths += dfs(grid, r + 1, c, remaining - 1);
        paths += dfs(grid, r - 1, c, remaining - 1);
        paths += dfs(grid, r, c + 1, remaining - 1);
        paths += dfs(grid, r, c - 1, remaining - 1);

        // Unmark so other paths can use this cell
        grid[r][c] = 0;

        return paths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int startRow = 0;
        int startCol = 0;
        int emptyCells = 0;

        // Find starting cell and count all non-obstacle cells
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != -1)
                    emptyCells++;

                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        return dfs(grid, startRow, startCol, emptyCells);
    }
};