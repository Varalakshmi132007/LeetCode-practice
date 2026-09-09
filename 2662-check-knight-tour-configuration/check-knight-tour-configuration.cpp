class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // Knight's possible 8 moves
        int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

        // Knight tour must start from (0,0)
        if (grid[0][0] != 0)
            return false;

        int r = 0;
        int c = 0;

        // Check positions 1, 2, 3, ... n*n-1
        for (int step = 1; step < n * n; step++) {

            bool found = false;

            for (int k = 0; k < 8; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                // Check boundaries
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {

                    // Check if this cell contains the next step
                    if (grid[nr][nc] == step) {
                        r = nr;
                        c = nc;
                        found = true;
                        break;
                    }
                }
            }

            // Next step was not found
            if (!found)
                return false;
        }

        return true;
    }
};