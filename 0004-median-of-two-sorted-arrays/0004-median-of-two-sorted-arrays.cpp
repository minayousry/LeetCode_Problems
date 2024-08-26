class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        multiset<int> nums;
        double result = 0;
        
        if((nums1.size() + nums2.size()) <= 1)
        {
            if(nums1.size() > 0)
            {
                result = nums1[0];
            }
            else if(nums2.size() > 0)
            {
                result = nums2[0];
            }
            //result = (double)(nums1.size() + nums2.size());
            
        }
        else if((nums1.size() == 1) && (nums2.size() == 1))
        {
           result = (((double)nums1[0] + (double)nums2[0])/2);  
        }
        else 
        {
            priority_queue<int> data;
            
            for(int i=0;i<nums1.size();++i)
            {
                data.push(nums1[i]);
            }
            
            for(int i=0;i<nums2.size();++i)
            {
                data.push(nums2[i]);
            }
            //data.push(nums1.begin(),nums1.end());
            //data.push(nums2.begin(),nums2.end());
            
            double mid1,mid2;
            
            int data_size = data.size();
            
            if(data_size %2 == 0)
            {
                while(data.size() > ((data_size/2) + 1))
                {
                    data.pop();
                }
                //cout<<data.top()<<" ";
                result = data.top();
                data.pop();
                //cout<<data.top()<<" "<<endl;
                result+= data.top();
                result = result/2;
            }
            else
            {
                //cout<<"hello world";
                while(data.size() > ((data_size/2) + 1))
                {

                    data.pop();
                }
                //cout<<data.top()<<" "<<endl;
                result = data.top();
                          
            }
            
        }
        return result;
    }
};