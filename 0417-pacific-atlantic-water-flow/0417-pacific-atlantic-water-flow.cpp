class Solution {
public:
    // Helper DFS: Water flows UPHILL from the ocean
    void dfs(vector<vector<int>>& heights, int r, int c, int prevHeight, vector<vector<bool>>& ocean) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Out of bounds check
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        
        // If we already visited this cell for this ocean, stop
        if (ocean[r][c]) return;
        
        // REVERSE FLOW: We can only flow to cells GREATER THAN or EQUAL to current height
        if (heights[r][c] < prevHeight) return;
        
        // Mark this cell as reachable by the current ocean
        ocean[r][c] = true;
        
        // Flow to all 4 neighbors
        dfs(heights, r + 1, c, heights[r][c], ocean);
        dfs(heights, r - 1, c, heights[r][c], ocean);
        dfs(heights, r, c + 1, heights[r][c], ocean);
        dfs(heights, r, c - 1, heights[r][c], ocean);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> result;
        
        // Two separate boolean grids to track reachability
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // 1. Flow uphill from the Left and Right edges
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, heights[i][0], pacific);     // Left edge (Pacific)
            dfs(heights, i, n - 1, heights[i][n - 1], atlantic); // Right edge (Atlantic)
        }
        
        // 2. Flow uphill from the Top and Bottom edges
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, heights[0][j], pacific);     // Top edge (Pacific)
            dfs(heights, m - 1, j, heights[m - 1][j], atlantic); // Bottom edge (Atlantic)
        }
        
        // 3. Find the intersection! 
        // If a cell is true in BOTH matrices, it flows to both oceans.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};