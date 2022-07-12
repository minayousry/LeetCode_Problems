class Solution {
public:
    
    int BFS(vector<vector<int>>& grid,pair<int,int> element,vector<vector<bool>> &visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        int no_of_connections = 0;
        
        pair<int,int> front_element;
        queue<pair<int,int>> elements;
        
        char directions_horizontal[2] = {1,-1};
        char directions_vertical[2]   = {1,-1};
        
        elements.push(element);
        visited[element.first][element.second] = true;
        no_of_connections++;
        
        while(!elements.empty())
        {
           front_element = elements.front();
           elements.pop();
            
            int new_index = 0;
            
            for(int v:directions_vertical)
            {
                new_index = front_element.first+v;
                
                if( ((new_index >= 0) && (new_index < m)) &&
                    (grid[new_index][front_element.second] == 1) &&
                    (visited[new_index][front_element.second] == false)
                  )
                {
                    elements.push(make_pair(new_index,front_element.second));
                    visited[new_index][front_element.second] = true;
                    no_of_connections++;
                }
            }
            
            for(int h:directions_horizontal)
            {
                new_index = front_element.second+h;
                
                if( ((new_index >= 0) && (new_index < n)) &&
                    (grid[front_element.first][new_index] == 1) &&
                    (visited[front_element.first][new_index] == false)
                  )
                {
                    elements.push(make_pair(front_element.first,new_index));
                    visited[front_element.first][new_index] = true;
                    no_of_connections++;
                }
            }
        }
        
        return no_of_connections;
        
        
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int max_connections = 0;
        int no_of_connections = 0;
        
        vector<vector<bool>> visited(m,vector<bool> (n, false)); 
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if((grid[i][j] == 1) && (visited[i][j] == false))
                {
                    pair<int,int> element = make_pair(i,j);
                    no_of_connections = BFS(grid,element,visited);
                    
                    if(no_of_connections > max_connections)
                    {
                        max_connections = no_of_connections;
                    }
                }
                
            }
        }
        
        return max_connections;
    }
};