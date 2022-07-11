class Solution {
public:
    
    void BFS(vector<vector<char>>& grid,pair<int,int> element,vector<vector<bool>> &visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        pair<int,int> front_element;
        queue<pair<int,int>> elements;
        
        char directions_horizontal[2] = {1,-1};
        char directions_vertical[2]   = {1,-1};
        
        elements.push(element);
        visited[element.first][element.second] = true;
        
        while(!elements.empty())
        {
           front_element = elements.front();
           elements.pop();
            
            int new_index = 0;
            
            for(int v:directions_vertical)
            {
                new_index = front_element.first+v;
                
                if( ((new_index >= 0) && (new_index < m)) &&
                    (grid[new_index][front_element.second] == '1') &&
                    (visited[new_index][front_element.second] == false)
                  )
                {
                    elements.push(make_pair(new_index,front_element.second));
                    visited[new_index][front_element.second] = true;
                }
            }
            
            for(int h:directions_horizontal)
            {
                new_index = front_element.second+h;
                
                if( ((new_index >= 0) && (new_index < n)) &&
                    (grid[front_element.first][new_index] == '1') &&
                    (visited[front_element.first][new_index] == false)
                  )
                {
                    elements.push(make_pair(front_element.first,new_index));
                    visited[front_element.first][new_index] = true;
                }
            }
        }
        
        
        
    }
        
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int no_of_islands = 0;
        
        vector<vector<bool>> visited(m,vector<bool> (n, false)); 
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if((grid[i][j] == '1') && (visited[i][j] == false))
                {
                    pair<int,int> element = make_pair(i,j);
                    BFS(grid,element,visited);
                    no_of_islands++;
                }
                
            }
        }
        
        return no_of_islands;
        
        
        
    }
};