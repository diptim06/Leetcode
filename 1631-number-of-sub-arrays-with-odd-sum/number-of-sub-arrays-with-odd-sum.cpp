class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long even = 1;
        long long odd = 0;
        long long prefixsum = 0;

        long long MOD = 1e9 + 7;

        for(int a : arr)
        {
            prefixsum += a;

            if(prefixsum %2 == 0)
                even++;
            else
                odd++;
        }

        return (even * odd) % MOD;
    }
};