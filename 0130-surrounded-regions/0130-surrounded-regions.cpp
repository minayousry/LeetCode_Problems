class Solution {
    int ROWS, COLS;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, 
                                         {0, 1}, {0, -1}};

public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();


        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
               if ((r == 0 || r == ROWS - 1 || c == 0 || c == COLS - 1) && board[r][c] == 'O')
                {
                    
                    capture(board,r,c);
                    
                }
            }
        }


        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }

private:
    void capture(vector<vector<char>>& board,int row,int col) {
        queue<pair<int, int>> q;

        q.push({row, col});
        board[row][col] = 'T';
    
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();

            for(int i=0;i<4;++i)
            {
                int new_row = r + directions[i][0];
                int new_col = c + directions[i][1];

                if(new_row >= 0 && new_row < board.size() &&
                    new_col >= 0 && new_col < board[0].size() && board[new_row][new_col] == 'O')
                {
                    board[new_row][new_col] = 'T';
                    q.push({new_row,new_col});
                }
                
            }
            
        }
    }
};