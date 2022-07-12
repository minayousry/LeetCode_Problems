class Solution {
public:
    
    bool DFS(unordered_map<int,vector<int>> &adjacent_list,
             unordered_set<int> &visited_courses,
             int crs_num)
    {
        if(visited_courses.find(crs_num) != visited_courses.end())
        {
            return false;
        }
        else if((adjacent_list.find(crs_num) != adjacent_list.end()) && (adjacent_list[crs_num].empty()))
        {
            return true;
        }
        
        visited_courses.insert(crs_num);
        
        for(int crs:adjacent_list[crs_num])
        {
               bool result = DFS(adjacent_list,visited_courses,crs);
               if(result == false)
               {
                   return false;
               }
        }
        adjacent_list[crs_num].clear();
        visited_courses.erase(crs_num);
        
        return true;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        bool result = true;
        unordered_map<int,vector<int>> adjacent_list;
        unordered_set<int> visited_courses;

        for(int i=0;i<prerequisites.size();++i)
        {
            adjacent_list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<numCourses;++i)
        {
            result &= DFS(adjacent_list,visited_courses,i);
            if(result == false)
            {
                break;
            }
        }
        
        return result;
    }
};