class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {

        int sum = 0;
        vector<int> data(nums.size() + 1,0);



        for (int i = 1; i <= nums.size(); i++)
        {
            data[i] = data[i -1] + nums[i-1];
            cout<<data[i]<<" ";            
        }
        cout<<endl;
            
    
        
        for (int i = 0; i < nums.size(); i++)
        {
            cout<<i<<endl;
            if(data[i] == (data[data.size() -1] - data[i+1]))
            {
                cout<<data[i]<<endl;
                cout<<data[data.size() -1]<<endl;
                cout<<data[i+1]<<endl;
                return i;
                
            }
        }
        return -1;
    }
};