class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int q = strs.size();

        for(int i = q-1; i>= 0; i--)
        {
            for(int j = m; j >= 0; j--)
            {
                for(int k = n; k>=0; k--)
                {
                    int z = 0, o = 0;

                    for(char s : strs[i])
                    {
                        if(s == '0')
                            z++;
                        
                        else
                            o++;
                    }

                    int exc = dp[j][k];

                    int inc = 0;
                    if(j-z >= 0 and k-o >=0)
                        inc = dp[j-z][k-o] + 1;

                    dp[j][k] = max(inc, exc);
                }
            }
        }

        return dp[m][n];
        
    }

};