
// bohut kuch sikhega isme ek bar pratice krna ache se

class Solution {
public:
 typedef long long ll ;
 const int MOD = 1e9 + 7 ; 
    int solve(int m , int n , int i  , int j ,  vector<vector<long long>>&freq , string & target, vector<vector<ll>> &dp  )
    {
        if(i == m) return 1 ;
        if(j==n) return 0 ; 
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        ll not_take = solve(m , n , i , j+1 , freq, target,dp) % MOD;
        ll take = freq[target[i]-'a'][j] * solve(m,n,i+1,j+1,freq,target,dp) % MOD;

         return dp[i][j] = (not_take + take ) % MOD ;
    }
    int numWays(vector<string>& words, string target) {
        int m = target.length();
        int n = words[0].length();

        vector<vector<long long>>freq(26,vector<long long>(n));
        // vector<vector<ll>>dp(10001,vector<ll>(10001,-1));
        vector<vector<ll>> dp(m+1, vector<ll>(n+1, -1));

        for(int col = 0 ; col < n ; col++)
        {
            for(string &word : words)
            {
                char ch = word[col];
                freq[ch-'a'][col]++;
            }
        }

        return solve(m , n ,0 , 0 , freq , target,dp);
    }
};
