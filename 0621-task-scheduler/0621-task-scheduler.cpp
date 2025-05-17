class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> tasks_data;
        priority_queue<int> tasks_info;
        int time = 0;

        for(int i=0;i < tasks.size();++i)
        {
            tasks_data[tasks[i]]++;
        }

        for(auto &task:tasks_data)
        {
            tasks_info.push(task.second);
        }

        queue<pair<int,int>> schedule;

        while(!tasks_info.empty() || !schedule.empty())
        {
            time += 1;

            if(!tasks_info.empty())
            {
                int task_count = tasks_info.top();
                tasks_info.pop();

                if(task_count > 1)
                {
                    schedule.push(make_pair((task_count - 1),time + n));
                }
            }

            if(!schedule.empty())
            {
                int task_time = schedule.front().second;
                
                if(task_time == time)
                {
                    int task_count = schedule.front().first;
                    schedule.pop();
                    tasks_info.push(task_count);
                }
            }
        }
        return time;
    }



};