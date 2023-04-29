class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {

        unordered_set<char> row_data;
        unordered_set<char> col_data;
        unordered_set<char> sub_square_data[3][3];
        

        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if((board[i][j] == '.') || (row_data.find(board[i][j]) == row_data.end()))
                {
                    
                    row_data.insert(board[i][j]);
                }
                else
                {
                    return false;
                }

                if((board[j][i] == '.') || (col_data.find(board[j][i]) == col_data.end()))
                {
                    col_data.insert(board[j][i]);
                }
                else
                {
                    return false;
                }

                if((board[i][j] == '.') || (sub_square_data[i/3][j/3].find(board[i][j]) == sub_square_data[i/3][j/3].end()))
                {
                    sub_square_data[i/3][j/3].insert(board[i][j]);
                }
                else
                {
                    return false;
                }
            }
            row_data.clear();
            col_data.clear();
        }



        return true;
        
    }
};