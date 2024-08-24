class Solution {
public:
    int findMin(vector<int>& nums) {

        int min_elm = static_cast<int>(*(std::min_element(nums.begin(),nums.end())));

        return min_elm;
        
    }
};