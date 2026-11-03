class Solution {
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (i >= days.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int option1 = costs[0] + solve(i + 1, days, costs, dp);

        int j = i;
        while (j < days.size() and days[j] < days[i] + 7) j++;
        int option2 = costs[1] + solve(j, days, costs, dp);

        int k = i;
        while (k < days.size() and days[k] < days[i] + 30) k++;
        int option3 = costs[2] + solve(k, days, costs, dp);

        return dp[i] = min({option1, option2, option3});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(0, days, costs, dp);
    }
};