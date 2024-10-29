// thora socha tha lekin jo map ander lena har bar ke loop wo nhi soch paya dusra glti ye hua ki me sort nhi soch skta tha wo ek learning tha 
//T.c O(n-k+1 * k * log(n))
// s.c O(n)  worst case



class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans(n-k+1,0);

        for(int i = 0 ;i<n-k+1;i++)
        {  
           unordered_map<int,int>mp;
            for(int j = i;j<k+i;j++)
            {
              mp[nums[j]]++;
            }
        
        vector<pair<int,int>>a;
        for(auto it : mp)
        {
            a.push_back({it.second,it.first});
        }
        sort(a.begin(),a.end(),greater<pair<int,int>>());
        for(int j = 0;j<a.size() && j<x;j++)
       {
          ans[i] += a[j].first * a[j].second;
       }
        }
       return ans;
    }
};
