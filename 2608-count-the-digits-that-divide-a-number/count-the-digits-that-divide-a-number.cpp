class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        int a = num;
        while(a>0)
        {
            int digit = a % 10;
            a /= 10;

            if(num % digit == 0)
                ans++;

        }

        return ans;
    }
};