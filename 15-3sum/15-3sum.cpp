class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> total_triplets;
        
        sort(nums.begin(),nums.end());

        long int sum;
        
        for(int i=0;i<nums.size() - 2;++i)
        {
            
            if((i > 0) && (nums[i - 1] == nums[i]))
                continue;
            
            int first_elm = nums[i];        
            int left_ptr = i+1;
            int right_ptr = nums.size() - 1; 
            
        
            
            
            while(left_ptr < right_ptr)
            {
                int second_elm = nums[left_ptr];
                int third_elm = nums[right_ptr];
                    
                sum = first_elm + second_elm + third_elm;
                          
                if(sum == 0)
                {
                    total_triplets.push_back({first_elm,second_elm,third_elm});
                    
                    do
                    {
                        left_ptr++;
                    }while((left_ptr < right_ptr) && (nums[left_ptr] == nums[left_ptr - 1]));
                    
                    do
                    {
                        right_ptr--;
                    }while((right_ptr > left_ptr) && (nums[right_ptr] == nums[right_ptr + 1]));
                    
                }
                else if(sum < 0)
                {
                    left_ptr++;
                }
                else
                {
                    right_ptr--;
                }
                
                
            }
                

        }
        return total_triplets;
    }
};