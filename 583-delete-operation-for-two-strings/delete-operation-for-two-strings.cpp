class Solution {
public:
    int minDistance(string word1, string word2) {

        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));

        return answer(word1, word2, word1.length(), word2.length(), dp);
    }

    int answer(string &word1, string &word2, int index1, int index2, vector<vector<int>> &dp){
        if(index1==0)
             return index2;
        if(index2==0)
            return index1;

        if(dp[index1][index2] != -1)
            return dp[index1][index2];

        int a = INT_MAX;

        if(word1[index1-1]==word2[index2-1]){
            a = answer(word1,word2,index1-1,index2-1,dp);
            return a;
        }
        else{
            int b = 1 + answer(word1,word2,index1-1,index2, dp);
            int c = 1 + answer(word1,word2,index1,index2-1, dp);
            return dp[index1][index2] = min(b,c);

        }
    }

};