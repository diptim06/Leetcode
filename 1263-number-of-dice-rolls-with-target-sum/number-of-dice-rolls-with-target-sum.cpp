class Solution {
public:
    const int modulo = 1e9 + 7;



    int numRollsToTarget(int n, int f, int target)
    {
        vector<vector<int>> dp(n+1 , vector<int>(target+1 , 0));


            dp[0][0] = 1;
        

        for(int i = 1 ; i<=n; i++)
        {
            
                for(int k = 1; k<=target ;k++)
                {
                    int ways = 0;
                    for(int faces = 1; faces <= f; faces++)
                    {
                        if(k>=faces)
                            ways = (ways + dp[i-1][k-faces]) % modulo;

                        else
                            break;
                    }
                    dp[i][k] = ways;
                }
            
        }

        return dp[n][target];
        
    }

};