class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        int last_stone = 0;
        
        if(stones.size() == 1)
        {
            last_stone = stones[0];
        }
        else
        {
            priority_queue<int> stones_weight;
            
            for(int stone:stones)
            {
                stones_weight.push(stone);
            }
            
            int stonex,stoney;
            while(!stones_weight.empty())
            {
                stonex = stones_weight.top();
                stones_weight.pop();
                stoney = stones_weight.top();
                stones_weight.pop(); 
                
                if(stonex != stoney)
                {
                   stones_weight.push(stonex - stoney);
                }
                
                if(stones_weight.size() == 1)
                {
                    last_stone = stones_weight.top();
                    stones_weight.pop(); 
                    break;
                }
                
            }
        }
        return last_stone;
    }
};