// tc O(log(max)*n)


class Solution {
public:
    bool isPossible(vector<int>&nums, int mid ,int maxOperations )
    {

        int totalOperation = 0 ; 
         
        
        for(int num : nums)
        {
            int op = 0 ; 
              op += num / mid ;

               if(num % mid == 0)
               {
                op = op -1 ; 
               }

               totalOperation += op ;
        }

        if(totalOperation> maxOperations)
        {
            return false;
        }

        return true;

    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1 ; 
        int r = *max_element(begin(nums),end(nums));
        int mid = 0 ; 
        int result = 0 ; 

        while(l<=r)  // binary search for O(log(max))
        {
            mid = l + (r-l)/2;

            if(isPossible(nums,mid,maxOperations))  // for n times 
            {
               result = mid ;
               r = mid-1;
            }
            else
            {
                l = mid + 1; 
            }
        }
        return result ; 

    }
};
