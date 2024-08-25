#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // Check if mid element is the minimum
            if (nums[mid] > nums[end]) {
                // Minimum is in the right half
                start = mid + 1;
            } else {
                // Minimum is in the left half or at mid
                end = mid;
            }
        }

        return nums[start];
    }
};
