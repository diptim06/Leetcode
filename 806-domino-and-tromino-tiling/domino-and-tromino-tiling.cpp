class Solution {
public:
    int modulo = 1e9+7;

    int numTilings(int n) {

        vector<vector<int>> dp(n, vector<int> (n, -1));

        return solve(n, 0, false, dp);
    }

    int solve(int &n, int j, bool gap, vector<vector<int>> &dp)
    {
        if(j==n and !gap)
            return 1;

        if(j>=n)
            return 0;

        if(dp[j][gap] != -1)
            return dp[j][gap];

        int dom1 = 0, dom2 = 0, trom1 = 0, trom2 = 0;

        if(!gap)
        {
            dom1 = solve(n, j+1, gap, dp)%modulo;
            dom2 = solve(n, j+2, gap, dp)%modulo;
            trom1 = solve(n, j+1, !gap, dp)%modulo;
            trom2 = solve(n, j+1, !gap, dp)%modulo;
        }

        if(gap)
        {
            trom2 = solve(n, j+2, !gap, dp)%modulo;
            dom2 = solve(n, j+1, gap, dp)%modulo;
            
        }
        
        return dp[j][gap] = ((((dom1 + dom2) % modulo) + trom1 )%modulo +trom2)%modulo;
    }
};