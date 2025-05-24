class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> weights(stones.begin(),stones.end());

        while(weights.size() > 1)
        {
            int weight1 = weights.top();
            weights.pop();
            int weight2 = weights.top();
            weights.pop();

            weights.push(abs(weight1 - weight2));
        }

        return weights.top();
    }
};