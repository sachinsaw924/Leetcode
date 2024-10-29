
// acha question tha isme or deep soch skta tha or test case kafi badhiya tha 
// T.c O(nlogn)

// s.c O(n)
 class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int>mp;
        sort(begin(nums),end(nums));
        int maxi = INT_MIN;

        int n = nums.size();
        
        for(int &num : nums)
        {
            int root = (int) sqrt(num);
            
             
            if( root * root == num && mp.find(root)!=mp.end()) 
            {        
                    mp[num] = mp[root] +1;
            }
            else
            {
                mp[num] = 1;
                // to handle the duplicate values i did not use mp[num]++;
            }
           maxi = max(maxi,mp[num]);
           
           
        }
   return    maxi <2  ? -1: maxi;
    }
};








// approach 2

// //T.C : O(n) ///Note : O(n) because while loop will run max 5 times. So if constraint is given, then saying O(n) time complexity is fine.
//S.C : O(n)
class Solutio
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int>st(begin(nums),end(nums));
        int n = nums.size();
        int maxi = 0 ;

        for(int &num : nums)
        {
            int streak = 0;
            long long curr = num;

            while(st.find(curr)!=st.end())
            {
                streak +=1;
                if(curr*curr> 1e5)
                {
                    break;
                }
                curr = curr * curr;
            }
           maxi = max(maxi,streak);
      }
      return maxi <2 ? -1 : maxi ;
    }
};
