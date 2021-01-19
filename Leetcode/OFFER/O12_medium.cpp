// 矩阵中的路径
// [["a","b","c","e"],
//  ["s","f","c","s"],
//  ["a","d","e","e"]]
// 存在"bfce"
class Solution {
private:
    int rows, cols;

public:
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int index){
        // 递归边界
        if(x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != word[index])
            return false;
        if(index == word.length() - 1)
            return true;
        // 访问过的点设为空字符
        board[x][y] = '\0';
        bool res = dfs(board, word, x+1, y, index + 1) ||
                   dfs(board, word, x-1, y, index + 1) ||
                   dfs(board, word, x, y+1, index + 1) ||
                   dfs(board, word, x, y-1, index + 1);
        // 回溯
        board[x][y] = word[index];
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() == 0)  return false;        
        rows = board.size();
        cols = board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};