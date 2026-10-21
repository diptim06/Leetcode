class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int n = name.size(), m = typed.size();

        for (int j = 0; j < m; j++) {
            if (i < n && typed[j] == name[i]) {
                i++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                continue;
            } else {
                return false;
            }
        }

        return i == n;
    }
};