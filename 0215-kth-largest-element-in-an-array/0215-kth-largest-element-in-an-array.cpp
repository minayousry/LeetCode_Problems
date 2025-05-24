class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> data(nums.begin(),nums.end()) ;

        while( !data.empty() && k > 1)
        {
            data.pop();
            k--;
        }

        return data.top();
    }
};