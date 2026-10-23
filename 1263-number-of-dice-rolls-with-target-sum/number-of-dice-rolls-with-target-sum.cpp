class Solution {
public:
    const int modulo = 1e9 + 7;



    int numRollsToTarget(int n, int f, int target)
    {
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(f+2 , vector<int>(target+1 , 0)));


        for(int i = 1; i<=f; i++)
        {
            dp[0][i][0] = 1;
        }

        for(int i = 1 ; i<=n; i++)
        {
            for(int j = f ; j>=1 ; j--)
            {
                for(int k = 1; k<=target ;k++)
                {

                    int incl = 0;
                    
                    if(k>=j)
                        incl = (dp[i-1][1][k-j]) % modulo;

                    int excl = (dp[i][j+1][k]) % modulo;

                    dp[i][j][k] = ((incl+excl)% modulo);
                }
            }
        }

        return dp[n][1][target];
        
    }

};