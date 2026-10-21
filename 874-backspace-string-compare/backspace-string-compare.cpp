class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> c;
        stack<char> d;

        for(char a : s)
        {
            if(a == '#')
            {
                if(!c.empty())
                    c.pop();
                
            }
            else
                c.push(a);
        }

        for(char a : t)
        {
            if (a == '#') {
                if (!d.empty()) 
                    d.pop();
            }    
            else
                d.push(a);
        }

        return c == d;
    }
};