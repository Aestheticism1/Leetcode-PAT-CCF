/**
 * 机器人的运动范围
 * 一个m*n的方格，机器人能上下左右移动一格，且行列坐标数位之和<=k
 * 问机器人能够到达多少个格子？
 */

// dfs
class Solution {
private:
    int rows, cols;

public:
    int helper(int n){
        int sum = 0;
        for(; n; n/=10)
            sum += n % 10;
        return sum;
    }

    int dfs(vector<vector<bool>>& visited, int x, int y, int k){
        if(x < 0 || x >= rows || y < 0 || y >=cols || visited[x][y] || helper(x) + helper(y) > k)
            return 0;
        visited[x][y] = true;
        return 1 + dfs(visited, x+1, y, k) + dfs(visited, x, y+1, k);
    }

    int movingCount(int m, int n, int k) {
        rows = m;
        cols = n;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        int ans = dfs(visited, 0, 0, k);
        return ans;
    }
};

// bfs
class Solution {
public:
    int helper(int n){
        int sum = 0;
        for(; n; n/=10)
            sum += n % 10;
        return sum;
    }

    int movingCount(int m, int n, int k) {
        if(!k)  return 1;
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        int ans = 1;
        while(!q.empty()){
            pair<int, int> point = q.front();
            q.pop();
            for(int i = 0; i < 2; i++){
                int xx = point.first + dx[i];
                int yy = point.second + dy[i];
                if(xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[xx][yy] && helper(xx) + helper(yy) <= k){
                    q.push({xx, yy});
                    visited[xx][yy] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};