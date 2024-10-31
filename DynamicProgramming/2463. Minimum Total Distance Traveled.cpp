// dekh me khud se nhi kiya hu 
// video dekha hai practice krna hai 
// Revision Mark : 0
// time complexity exponential hai

class Solution {
public:
  typedef long long ll;

  ll solve(int i ,int j , vector<int>& robot ,vector<int>& positions, vector<vector<ll>>&dp)
  {
     if(i>=robot.size()) return 0;
     if(j>= positions.size()) return 1e12;
     if(dp[i][j]!=-1)
     {
        return dp[i][j];
     }

     ll take = abs(robot[i]-positions[j]) + solve(i+1,j+1,robot ,positions,dp);
     ll skip = solve(i,j+1,robot,positions,dp);
      return dp[i][j] = min(take,skip);
    




  }

    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot),end(robot));
        sort(begin(factory),end(factory));
         
        
        vector<int>positions;

        for(int i  = 0 ;i<factory.size();i++)
        {
            int limit = factory[i][1];
            int position = factory[i][0];
            for(int j = 0 ;j<limit;j++)
            {
                positions.push_back(position);
            }
        }
        int m = robot.size();
        int n = positions.size();
        vector<vector<ll>>dp(m+1,vector<ll>(n+1,-1));
        return solve(0,0,robot,positions,dp); 
    }
};
