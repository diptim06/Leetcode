class Solution {
public:
    bool canAliceWin(int n) {
        int c = 0;
        int i = 0;
        int ten = 10;
        while(n>0)
        {
            if(n >= ten-i)
            {
                n -= (ten-i);
                c++;
            }
            else
            {
                break;
            }
            i++;
        }

        return c%2 == 0 ? false : true;
    }
};