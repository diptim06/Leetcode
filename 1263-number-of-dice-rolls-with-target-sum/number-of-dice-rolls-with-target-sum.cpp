class Solution {
public:
    const int modulo = 1e9 + 7;



    int numRollsToTarget(int n, int f, int target)
    {
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(f+1 , vector<int>(target+1 , -1)));

        // for(int i = 0 ; i<=n i++)
        // {
        //     for(int j = f ; j>=0 ; j++)
        //     {
        //         for(int k = 0 ; k<=taget ;k++)
        //         {


        //         }
        //     }
        // }

        return solve(n , f , target , 1 , dp);
        
    }


    int solve(int n , int f ,  int target , int currFace ,vector<vector<vector<int>>> &dp)
    {
        if(n==0 and target==0)
            return 1;

        if(n<0 or currFace > f or target<0)
            return 0;

            if(dp[n][currFace][target] != -1)
                return dp[n][currFace][target] ;


        int incl = (solve(n-1 , f , (target-currFace),(1) , dp)) % modulo;

            

        int excl = (solve(n , f , target , currFace + 1 , dp))% modulo;

        return dp[n][currFace][target] = ((incl+excl)% modulo);

        
    }


};