class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> output(nums.size(),1);

        for(int i=1;i<output.size();++i)
        {
            output[i] = output[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for(int i = output.size() - 1 ;i>=0;--i)
        {   
            output[i] = output[i] * postfix; 
            postfix*= nums[i];
        }
        return output;

    }
};