class Solution {
constexpr static int dx[4] = {0, 1, 0, -1};
constexpr static int dy[4] = {1, 0, -1, 0};

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int p, q;
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    for(int k = 0; k < 4; k++){
                        p = i + dx[k];
                        q = j + dy[k];
                        if(p < 0 || p >= n || q < 0 || q >= m || !grid[p][q])
                            count++;
                    }
                }
            }
        }
        return count;
    }

    int dfs(int x, int y, vector<vector<int>> &grid, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
            return 1;
        }
        if (grid[x][y] == 2) {
            return 0;
        }
        grid[x][y] = 2;
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            res += dfs(tx, ty, grid, n, m);
        }
        return res;
    }

    int islandPerimeter_dfs(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += dfs(i, j, grid, n, m);
                }
            }
        }
        return ans;
    }

};