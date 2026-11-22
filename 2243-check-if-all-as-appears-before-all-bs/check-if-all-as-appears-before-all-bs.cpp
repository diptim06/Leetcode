class Solution {
public:
    bool checkString(string s) {
        int counta = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == 'a')
                counta++;
        }

        for(int i = 0; i<s.size(); i++)
        {   
            if(s[i] == 'b' and counta!=0)
                return false;

            if(s[i]== 'a')
                counta--;
        }

        return true;
    }
};