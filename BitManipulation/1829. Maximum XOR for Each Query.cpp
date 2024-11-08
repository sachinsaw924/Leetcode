
// space complexity o(n)
// time complexity O(n)
// myself
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int value = (1<<maximumBit)-1;
        int n = nums.size();
        vector<int>ans;
        vector<int>cumuXor;
        int output = 0 ;


        for(int i= 0;i<n;i++)
        {
            output = output^nums[i];
            cumuXor.push_back(output);
        }
        // reverse(cumuXor.begin(),cumuXor.end());

        for(int i = 0 ;i<n;i++)
        {
            ans.push_back(abs(cumuXor[n-i-1]-value));
        }
         
      return ans;
    }
};



// sir ka approach hai

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>result  ;
        int n = nums.size();
        int xorOutput = 0 ;

        for(int i = 0 ;i<n;i++)
        {
            xorOutput ^=nums[i];
        }

        int mask = (1<<maximumBit)-1;

        for(int i = 0 ;i<n;i++)
        {
            int k = mask ^ xorOutput;

            result.push_back(k);
            xorOutput ^= nums[n-i-1];

            
        }
        return result;
    }
};





