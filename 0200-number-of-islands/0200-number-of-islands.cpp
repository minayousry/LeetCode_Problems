class Solution {
public:
    int moves[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    void checkIsland2(vector<vector<char>>& grid,int row,int col)
    {
        if(row < 0 || row >=  grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0')
        {
            return;
        }

        grid[row][col] = '0';
        
        int new_row,new_col;

        for(int i=0;i<4;++i)
        {
            new_row = row + moves[i][0];
            new_col = col + moves[i][1];

            checkIsland2(grid,new_row,new_col);
        }

        
    }
    
    
    void checkIsland(vector<vector<char>>& grid,int i,int j)
    {
        queue<pair<int,int>> points;

        points.push({i,j});
       

        while(!points.empty())
        {
            auto point = points.front();
            points.pop();

            int row = point.first;
            int col = point.second;
            
            for(int i=0;i<4;++i)
            {
                int x_index =  row + moves[i][0];
                int y_index =  col + moves[i][1];
                
                if(x_index >=0 && x_index < grid.size() && y_index >=0 && y_index < grid[0].size() &&
                 grid[x_index][y_index] == '1')
                 {
                    points.push({x_index,y_index});
                    grid[x_index][y_index] = '0';

                 }
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {

        int numIslands = 0;
        
        for(int i=0;i< grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                
                if(grid[i][j] == '1')
                {
                    checkIsland2(grid,i,j);
                    grid[i][j] = '0';
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
};