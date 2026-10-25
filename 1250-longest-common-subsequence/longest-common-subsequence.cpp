class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        vector<int> nr(b.length()+1, 0);
        vector<int> cr(b.length()+1, 0);
        
        

        for(int i = a.length()-1; i>=0; i--)
        {
            for(int j = b.length()-1; j>=0; j--)
            {
                
                int ni = nr[j];
                int nj = cr[j+1];
                int nij = nr[j+1];

                int ans = 0;

                if(a[i] == b[j])
                {
                    ans = 1 + nij;
                }
                else
                {
                    ans = max(ni, nj);
                }

                cr[j] = ans;
            }
            nr = cr;
        }

        return nr[0];;
    }

};