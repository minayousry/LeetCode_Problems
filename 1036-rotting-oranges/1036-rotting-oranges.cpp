class Solution {
public:
    vector<vector<int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
     
    int orangesRotting(vector<vector<int>>& grid)
    {
        int time = 0;
        int fresh_orangs = 0;
        queue<pair<int,int>> oranges;


        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j] == 2)
                {
                    oranges.push({i,j});
                }
                else if(grid[i][j] == 1)
                {
                    fresh_orangs++;
                }
            }
        } 


        while(!oranges.empty() && fresh_orangs > 0)
        {

            int num_oranges = oranges.size();
            for(int n=0;n<num_oranges;++n)
            {

                pair<int,int> orange = oranges.front();
                oranges.pop();
                grid[orange.first][orange.second] = 0;

                for(int i=0;i<4;++i)
                {
                    int new_row = orange.first + moves[i][0];
                    int new_col = orange.second + moves[i][1];

                    if(new_row >= 0 && new_row < grid.size() && new_col >= 0 && new_col < grid[new_row].size() && grid[new_row][new_col] == 1)
                    {
                        fresh_orangs--;
                        grid[new_row][new_col] = 2;
                        oranges.push({new_row,new_col}); 
                     
                    }
                }
            }
            time++;
        }


        if(fresh_orangs > 0)
        {
            time = -1;
        }


        return time;   
    }
};