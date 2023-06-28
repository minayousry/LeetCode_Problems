class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0;
        int right = int(numbers.size()) - 1;
        vector<int> ans;
        int sum;

        while (left < right) {
            // do some logic here with left and right
            sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
                
            }
            else if(sum > target)
            {
                right--;
            } 
            else
            {
                left++;
            }
        }

        return ans;
        
    }
};