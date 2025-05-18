class Solution {
public:
    bool backtrack(vector<vector<char>> &board,int row,int col,int index,string &word,vector<vector<bool>> &used)
    { 
        bool result = true;          
        if(index == word.size())
        {
            return true;
        }
        else if( (row < 0) || (row >= board.size()) || (col < 0) ||
                 (col >= board[row].size()) || (board[row][col] != word[index]) || used[row][col] )
        {
            return false;
        }
        else
        {
            used[row][col] = true;
            result = backtrack(board,row + 1,col,index + 1,word,used) || 
                    backtrack(board,row - 1,col,index + 1,word,used) ||
                    backtrack(board,row,col + 1,index + 1,word,used) ||
                    backtrack(board,row,col - 1,index + 1,word,used);
            
            used[row][col] = false;
            
            return result;

        }




    } 

    bool exist(vector<vector<char>>& board, string word) {
        
        bool result = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i=0;i<board.size();++i)
        {
            for(int j = 0;j<board[i].size();++j)
            {
                if(backtrack(board,i,j,0,word,visited))
                {
                    return true;
                }
            }
        }
        return result;
    }
};