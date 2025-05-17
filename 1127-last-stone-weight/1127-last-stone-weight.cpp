class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pack;
        int result = -1;

        for(const auto& stone:stones)
        {
            pack.push(stone);
        }

        int stone1,stone2;

        while(!pack.empty())
        {
            stone1 = pack.top();
            pack.pop();

            if(!pack.empty())
            {
                stone2 = pack.top();
                pack.pop();

                int smash = abs(stone1 - stone2);
                pack.push(smash);   
            }
        }

        return stone1;
    }
};