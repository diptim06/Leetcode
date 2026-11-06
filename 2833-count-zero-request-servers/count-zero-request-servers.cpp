
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        int m = logs.size();
        int k = queries.size();

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < k; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(k);

        int left = 0, right = 0;
        int activeServers = 0;

        for (auto [q, idx] : sortedQueries) {

            // Add logs up to the query time
            while (right < m && logs[right][1] <= q) {
                int id = logs[right][0];

                if (freq[id] == 0) {
                    activeServers++;
                }

                freq[id]++;
                right++;
            }

            // Remove logs outside the interval
            while (left < right && logs[left][1] < q - x) {
                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0) {
                    activeServers--;
                }

                left++;
            }

            // Store the answer at the original query index
            ans[idx] = n - activeServers;
        }

        return ans;
    }
};