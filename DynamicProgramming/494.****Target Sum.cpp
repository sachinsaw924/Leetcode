
class Solution {
public:
  int solve(vector<int>& nums , int index, int currSum , int target,unordered_map<string,int>&mp)
  {
    if(index == nums.size())
    {
        if(currSum == target)
        {
            return 1 ;
        }
        else
        {
            return 0 ; 
        }
    }

    string key = to_string(index) +"_" + to_string(currSum);
    if(mp.count(key))
    {
        return mp[key];
    }

    int plus = solve(nums, index+1 , currSum + nums[index] ,target,mp);
    int minus = solve(nums , index + 1 , currSum - nums[index] , target,mp);

    return mp[key] =  plus + minus ; 
  }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>mp;
       return solve(nums, 0 , 0 , target,mp); 
    }
};











// 2number solution 


class Solution {
public:
  int solve(vector<int>& nums , int index, int currSum , int target,int totalSum, vector<vector<int>>&dp )
  {
    if(index == nums.size())
    {
        if(currSum == target)
        {
            return 1 ;
        }
        else
        {
            return 0 ; 
        }
    }

    if(dp[index][currSum+totalSum] != -1)  // ye isliye add kyunki yanha number negative bhi ja skta tha wo 
                                            // invalid hota bs shift kiye hai index agr man lo pehle -5 se 5 tak tha
                                           // to ab 0 se 10 tak hoga
      
    {
        return dp[index][currSum + totalSum];
    }

    int plus = solve(nums, index+1 , currSum + nums[index] ,target,totalSum, dp );
    int minus = solve(nums , index + 1 , currSum - nums[index] , target,totalSum,dp );

    return dp[index][currSum+ totalSum]  =  plus + minus ; 
  }
    int findTargetSumWays(vector<int>& nums, int target) {
         int totalSum = accumulate(begin(nums),end(nums),0);
         int n = nums.size();
         vector<vector<int>>dp(n+1,vector<int>(2*totalSum +1,-1));
       return solve(nums, 0 , 0 , target,totalSum ,dp); 
    }
};
