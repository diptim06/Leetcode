class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int j = 0;
        for(int i = 0; i<s.length(); i++)
        {
            if(j < spaces.size() and i == spaces[j])
            {
                ans+= ' ';
                j++;
                i--;
            }
            else
                ans+= s[i];
        }

        return ans;
    }
};