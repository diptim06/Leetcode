class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        int q = strs.size();

        for(int i = q-1; i>= 0; i--)
        {
            for(int j = 0; j<=m; j++)
            {
                for(int k = 0; k<=n; k++)
                {
                    int z = 0, o = 0;

                    for(char s : strs[i])
                    {
                        if(s == '0')
                            z++;
                        
                        else
                            o++;
                    }

                    int exc = dp[i+1][j][k];

                    int inc = 0;
                    if(j-z >= 0 and k-o >=0)
                        inc = dp[i+1][j-z][k-o] + 1;

                    dp[i][j][k] = max(inc, exc);
                }
            }
        }

        return dp[0][m][n];
        
    }

};