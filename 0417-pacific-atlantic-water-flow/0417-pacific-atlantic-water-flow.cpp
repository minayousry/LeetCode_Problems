class Solution {
public:
    vector<vector<int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};

    void bfs(vector<vector<int>>& heights,queue<pair<int,int>> &ocean_data,vector<vector<bool>> &visited)
    {

        while(!ocean_data.empty())
        {
            auto [row,col] = ocean_data.front();
            ocean_data.pop();
            visited[row][col] = true;

            for(int i=0;i<4;++i)
            {
                int new_row = row + moves[i][0];
                int new_col = col + moves[i][1];

                if(new_row >= 0 && new_row < heights.size() && new_col >= 0 && new_col < heights[0].size() && !visited[new_row][new_col] &&
                    heights[new_row][new_col] >=  heights[row][col])
                {
                    ocean_data.push({new_row,new_col});
                }
            }

            
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> res;

        vector<vector<bool>> visited_pacific(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> visited_atlantic(heights.size(),vector<bool>(heights[0].size(),false));

        queue<pair<int,int>> pacific_queue;
        queue<pair<int,int>> atlantic_queue;

        int rows = heights.size();
        int cols = heights[0].size();
         

        for(int i=0;i<rows;i++)
        {
            pacific_queue.push({i,0});            
            atlantic_queue.push({i,cols - 1});
        }

        for(int j=0;j<cols;j++)
        {
            pacific_queue.push({0,j});
            atlantic_queue.push({rows - 1,j});
        }


        bfs(heights,pacific_queue,visited_pacific);
        bfs(heights,atlantic_queue,visited_atlantic);
        
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(visited_pacific[i][j] && visited_atlantic[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }

        

        return res;
        
    }
};