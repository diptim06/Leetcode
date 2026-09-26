class Solution {
public:
    int climbStairs(int n) {

        int next1 = 1, next2 = 1;
        int curr;
        for(int i = n-1; i>=0; i--)
        {
            if(i == n-1)
            {
                curr = next1;
                next2 = next1;
                next1 = curr;
            }
            else
            {
                curr = next1+next2;
                next2 = next1;
                next1 = curr;
            }
        }
        return curr;
    }

    
};