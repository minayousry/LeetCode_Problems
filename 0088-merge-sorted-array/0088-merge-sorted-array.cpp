class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        multiset<int> output;
        bool first_time = true;
        
        for(int i=0;i<m;++i)
        {
            output.insert(nums1[i]);
        }
        
        for(int i=0;i<n;++i)
        {
            output.insert(nums2[i]);
        }
        
        nums1.clear();
        
        for(auto elm:output)
        {
            nums1.push_back(elm);
        }
        
    }
};