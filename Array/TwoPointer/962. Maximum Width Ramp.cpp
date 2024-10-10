

 // approach ! 
// Revision mark : 0
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
     int maxi = 0;
     int n = nums.size();
     for(int i = 0;i<n;i++)
     {
        for(int j = i ;j<n;j++)
        {
            if(i<j  && nums[i]<=nums[j])
            {
                maxi = max(maxi,j-i);
            }
        }
     }
     return maxi;   
    }
};



//Apraoch 2 
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxi  = INT_MIN;
        int min = INT_MAX;
        int ramp = 0;
        int n = nums.size();
        for(int i = 0 ;i<n;i++)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(nums[i]<=nums[j])
                {
                    ramp = max(ramp,j-i);
                    break;
                }

            }
        }
        
        return ramp;
    }
};


//Appraoch 3 : taken hint 
//Revision mark : 0
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
      int n = nums.size();
      vector<int>rightMax(n);
      rightMax[n-1] =  nums[n-1];
      for(int i = n-2;i>=0;i--)
      {
        rightMax[i] = max(rightMax[i+1],nums[i]);
      }
      int i = 0;  // nums array ke liye
      int j = 0;  // rightMax array ke liye
      int ramp = INT_MIN;
      while(j<n)
     {
          while(i<j && nums[i]>rightMax[j])
          {
             i++;
          }
          ramp = max(ramp,j-i);
          j++;

     }

   return ramp;
    }
};
