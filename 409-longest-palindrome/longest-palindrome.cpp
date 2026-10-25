class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(52, 0);

        for(char i : s)
        {
            if( i >= 'A' and i <= 'Z')
                mp[i-'A']++;
            else
                mp[i-'a' + 26]++;
        }
        int ans = 0;

        for(int i = 0; i < 52; i++)
        {
            if(mp[i]%2 == 0)
                ans+= mp[i];

            else
                ans+= mp[i]-1;

        }

        for(int i = 0; i < 52; i++)
        {
            if(mp[i]%2 != 0)
            {    ans++;
                break;
            }

        }
        return ans;
    }
};