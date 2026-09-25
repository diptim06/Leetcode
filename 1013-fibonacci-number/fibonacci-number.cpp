class Solution {
public:

    int fib(int n) {
        
        int prev1 = 0;
        int prev2 = 1;

        int curr;

        if(n==0 or n==1)
            return n;


        for(int i = 1; i<=n; i++)
        {
            curr = prev1+ prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};