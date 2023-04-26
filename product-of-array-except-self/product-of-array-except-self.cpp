class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        // Count the number of zeros in nums
        int prefix[nums.size()];
        int postfix[nums.size()];
        vector<int> answer(nums.size(),0);

        prefix[0] = 1;
        for(int i=1;i<nums.size();++i)
        {
            prefix[i] = prefix[i - 1] *nums[i - 1];
        }


        postfix[nums.size() - 1] = 1;

        for(int i=nums.size() - 2;i>=0;--i)
        {
            postfix[i] = postfix[i + 1] *nums[i + 1];
        }

        for(int i=0;i<nums.size();++i)
        {
            answer[i] = prefix[i]*postfix[i];
        }





    
        return answer;
    }
};