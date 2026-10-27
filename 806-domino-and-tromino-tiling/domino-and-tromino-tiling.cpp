class Solution {
public:
    int modulo = 1e9+7;

    int numTilings(int n) {
        vector<vector<int>> dp(n+2, vector<int> (2, 0));

        dp[n][0] = 1;

        for(int j = n-1; j>=0 ; j--)
        {
            for(int gap = 1; gap>=0; gap--)
            {
                int dom1 = 0, dom2 = 0, trom1 = 0, trom2 = 0;

                if(!gap)
                {
                    dom1 = dp[j+1][0]%modulo;
                    dom2 = dp[j+2][0]%modulo;
                    trom1 = dp[j+1][1] % modulo;
                    trom2 = dp[j+1][1]%modulo;
                }
                if(gap)
                {
                    trom2 = dp[j+2][0]%modulo;
                    dom2 = dp[j+1][1]%modulo;
                    
                }
                dp[j][gap] = ((((dom1 + dom2) % modulo) + trom1 )%modulo +trom2)%modulo;
            }
        }
        return dp[0][0];
    }

    // int solve(int &n, int j, bool gap, vector<vector<int>> &dp)
    // {
    //     if(j==n and !gap)
    //         return 1;

    //     if(j>=n)
    //         return 0;

    //     if(dp[j][gap] != -1)
    //         return dp[j][gap];

    //     int dom1 = 0, dom2 = 0, trom1 = 0, trom2 = 0;

    //     if(!gap)
    //     {
    //         dom1 = solve(n, j+1, gap, dp)%modulo;
    //         dom2 = solve(n, j+2, gap, dp)%modulo;
    //         trom1 = solve(n, j+1, !gap, dp)%modulo;
    //         trom2 = solve(n, j+1, !gap, dp)%modulo;
    //     }

    //     if(gap)
    //     {
    //         trom2 = solve(n, j+2, !gap, dp)%modulo;
    //         dom2 = solve(n, j+1, gap, dp)%modulo;
            
    //     }
        
    //     return dp[j][gap] = ((((dom1 + dom2) % modulo) + trom1 )%modulo +trom2)%modulo;
    // }
};