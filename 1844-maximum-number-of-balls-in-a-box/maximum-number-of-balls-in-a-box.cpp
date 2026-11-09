class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> boxes;

        for(int i = lowLimit; i <= highLimit; i++) {
            int num = i, sum = 0;
            while(num) {
                int digit = num % 10;
                sum += digit;
                num /= 10;
            }
            boxes[sum]++;
        }

        int maximum_balls = 0;
        for(auto it : boxes)
            maximum_balls = max(maximum_balls, it.second);
        
        return maximum_balls;
    }
};