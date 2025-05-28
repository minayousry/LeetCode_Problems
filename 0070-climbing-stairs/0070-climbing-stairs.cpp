class Solution {
public:
    int climbStairs(int n) {
        int two = 1;
        int one = 1;
        vector<int> data(n,0);
        for(int i = 0; i < n - 1 ;++i)
        {

            int temp = one;
            one = one + two;
            two = temp;
        }

        return one;
    }
};