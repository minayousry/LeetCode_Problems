class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        bool is_valid = true;
        unordered_map<char,char> row_digits_map;
        unordered_map<char,char> col_digits_map;
        unordered_map<char,char> micro_digits_map[3][3];
        bool exit = false;
        
        
        
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            { 
                if(board[i][j] != '.')
                {
                    row_digits_map[board[i][j]]+=1;
                    if(row_digits_map[board[i][j]] > 1)
                    {
                        is_valid = false;
                        exit = true;
                        break;
                    }
                    
                    
                    micro_digits_map[i/3][j/3][board[i][j]]+=1;
                    
                    if(micro_digits_map[i/3][j/3][board[i][j]] > 1)
                    {
                        is_valid = false;
                        exit = true;
                        break;
                    }
                    
                    
                }
                
                if(board[j][i] != '.')
                {  
                    col_digits_map[board[j][i]]+=1;
                    if(col_digits_map[board[j][i]] > 1)
                    {
                        //cout<<"here 3";
                        is_valid = false;
                        exit = true;
                        break;
                    }
                }
            }
            row_digits_map.clear();
            col_digits_map.clear();
            
            
            if(exit == true)
            {
                break;
            }
        }
        
        return is_valid;
        
    }
};