// approach 1 : Revise once again this problem 
// Revision mark : 0
// This is solve by general bracktracking method khandani template 

// T.C O(n*n!)
// s.c O(n)
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


//now swap methoding used
// make tree diagram again while revising 
// Revision mark : 0





class Solution {
public:
      vector<vector<int>>result;
      int n ;
      void solve(int idx,vector<int>& nums)
      {
        if(idx == n )
        {
            result.push_back(nums);
            return  ;
        }

        for(int i = idx ;i < n ; i++)
        {
            swap(nums[i],nums[idx]);
            solve(idx+1,nums);
            swap(nums[i],nums[idx]);
        }
      }
    vector<vector<int>> permute(vector<int>& nums) {
        int i = 0;
        n = nums.size();
        solve(i,nums);
        return result;
    }
};
