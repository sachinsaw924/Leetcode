typedef long long ll;
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        // time complexity is O(n)
        //space complexity is O(n)
      int m = nums1.size();
      int n = nums2.size();
      unordered_map<ll,ll>mp;

      for(int &num : nums1)
      {
          mp[num] += n;
      }  
      for(int &num : nums2)
      {
        mp[num] += m;
      } 
         int result = 0 ;
      for(auto &it : mp)
      {
        int num = it.first;
        int freq = it.second;

        if(freq %2 != 0)
        {
            result = result ^ num ;
        }
      }

      return result;


// approach 2 it is good 


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size();
       int n = nums2.size();
       int result = 0 ;

       if(m%2 == 0 && n %2 == 0 )
       {
        return 0 ;
       }

       if(m %2 != 0 && n %2 == 0)
       {
            for(int i = 0 ; i < n ; i++)
            {
                result = result ^ nums2[i];
            }
            return result;
       } 
       else if( n %2 != 0  && m%2 ==0)
       {
         for(int i = 0 ; i < m;i++)
         {
            result = result ^ nums1[i];
         }
       }
       else
       {
        for(int &num : nums1)
        {
            result = result ^ num;
        }
        for(int &num : nums2)
        {
            result = result ^ num;
        }
        return result;

       }

       return result;
    }
};
