class Solution {
public:
    int numTilePossibilities(string tiles) {
        int freq[26] = {0};
        for (char c : tiles) {
            freq[c - 'A']++;
        }
        return dfs(freq);
    }

private:
    int dfs(int freq[26]) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                freq[i]--;
                count += 1 + dfs(freq);
                freq[i]++;
            }
        }
        return count;
    }
};