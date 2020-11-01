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
};