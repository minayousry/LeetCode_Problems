class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<int,int> tasks_freq;

        for(auto &task:tasks)
        {
            tasks_freq[task]++;
        }

        priority_queue<int> tasks_count;

        for(auto &task:tasks_freq)
        {
            tasks_count.push(task.second);
        }

        queue<pair<int,int>> tasks_schedule;
        int time = 0;
        while(!tasks_count.empty() || !tasks_schedule.empty())
        {
            time++;

            if(!tasks_count.empty())
            {
                auto task_count = tasks_count.top();
                tasks_count.pop();
                
                if(task_count > 1)
                {    
                    tasks_schedule.push({task_count - 1,time + n});
                }
                
            }

            if(!tasks_schedule.empty())
            {
                auto task_data = tasks_schedule.front();

                if(time == task_data.second)
                {
                    tasks_schedule.pop();
                    tasks_count.push(task_data.first);
                }
            }
        }

        return time;



    }
};