class Solution {
public:
    
    bool DFS(unordered_map<int,vector<int>> &adjacent_list,
             unordered_set<int> &cyclic_courses,
             unordered_set<int> &visited_courses,
             int crs_num,
             vector<int> &courses_order)
    {
        if(cyclic_courses.find(crs_num) != cyclic_courses.end())
        {
            return false;
        }
        else if(visited_courses.find(crs_num) != visited_courses.end())
        {
            return true;
        }
        
        cyclic_courses.insert(crs_num);
        
        
        
        for(int crs:adjacent_list[crs_num])
        {
               bool result = DFS(adjacent_list,cyclic_courses,visited_courses,crs,courses_order);
               if(result == false)
               {
                   return false;
               }
        }
        adjacent_list[crs_num].clear();
        cyclic_courses.erase(crs_num);
        visited_courses.insert(crs_num);
        courses_order.push_back(crs_num);
    
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        bool result = true;
        vector<int> courses_order;
        unordered_map<int,vector<int>> adjacent_list;
        unordered_set<int> visited_courses;
        unordered_set<int> cyclic_courses;

        for(int i=0;i<prerequisites.size();++i)
        {
            adjacent_list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<numCourses;++i)
        {
            result &= DFS(adjacent_list,cyclic_courses,visited_courses,i,courses_order);
            if(result == false)
            {
                return {};
            }
        }
        
        return courses_order;
    }
};