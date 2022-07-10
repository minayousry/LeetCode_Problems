class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int prefixes[nums.size() ];
        int postfixes[nums.size()];
        

        
        vector<int> values;

        
        int prefix = 1;
        int postfix = 1;
        
        for(int i=0;i<nums.size();++i)
        {
            prefixes[i] = nums[i]*prefix;
            prefix *= nums[i];
            //cout<<prefixes[i]<<" "; 
        }
        cout<<endl;
        
        for(int i=nums.size() - 1;i>=0;--i)
        {
            postfixes[i] = nums[i]*postfix;
            postfix *= nums[i];
            //cout<<postfixes[i]<<" "; 
        }
        
        for(int i=0;i<nums.size();++i)
        {
            if((i + 1) > (nums.size() - 1))
            {
                values.push_back(prefixes[i - 1]);
            }
            else if((i-1) < 0)
            {
                values.push_back(postfixes[i + 1]);
            }
            else
            {
                values.push_back(prefixes[i - 1]*postfixes[i + 1]);
            }
        }
        
        
        return values;
    }
};