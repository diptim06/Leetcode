class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int ab = 0, nab = 0;
        int cb = 0, cnb = 0;

        for(int i = prices.size()-1; i>= 0; i--)
        {    
            cb = max((-(prices[i]) + nab) , (0 + ab));
                
            cnb = max((prices[i] + ab), (0 + nab));

            ab = cb;
            nab = cnb;
            
        }

        return ab;
    }

};