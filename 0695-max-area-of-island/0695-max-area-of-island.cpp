class Solution {
public:
    vector<vector<int>> directions = {{1,0,},{-1,0},{0,1},{0,-1}};

    int getMaxIslands(vector<vector<int>>& grid,vector<vector<bool>> &visited,int row,int col)
    {
        int max_islands = 1;
        queue<pair<int,int>> islands;
        

        islands.push(make_pair(row,col));

        while(!islands.empty())
        {
            pair<int,int> island = islands.front();
            visited[row][col] = true;
            islands.pop();    

            for(int i=0;i<4;i++)
            {
                int new_row = island.first + directions[i][0];
                int new_col = island.second + directions[i][1];
                
                if(new_row >=0 && new_row < grid.size() && new_col >= 0 && new_col < grid[0].size() && 
                    (visited[new_row][new_col] == false) && grid[new_row][new_col] == 1)
                {
                    islands.push(make_pair(new_row,new_col));
                    visited[new_row][new_col] = true;
                    max_islands++;
                }
                
            }

        }
        return max_islands;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int islands = 0;

        int max_no = 0;

        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));

        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    islands = getMaxIslands(grid, visited, i, j); 
                    max_no = max(max_no,islands);
                }
            
            }
        }

        return max_no; 
    }
};