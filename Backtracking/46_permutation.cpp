class Solution {
public:
  
  void solve(vector<int>&temp,vector<int>& nums, vector<vector<int>>&result,unordered_set<int>&st)
  { 

     
     if(temp.size()==nums.size())
      {
        result.push_back(temp);
        return ;
      }
       for(int i = 0 ;i<nums.size();i++)
        {
            if(st.find(nums[i])==st.end())
            {   temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(temp,nums,result,st);
                temp.pop_back();
                st.erase(nums[i]);


            }
        }
  }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
        unordered_set<int>st;
        solve(temp,nums,result,st);
        return result;
 
    }
};
